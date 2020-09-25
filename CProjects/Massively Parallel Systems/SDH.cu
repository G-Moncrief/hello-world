/* ==================================================================
	Programmer: Yicheng Tu (ytu@cse.usf.edu)
  Modified By: Garrett Moncrief
	The basic SDH algorithm implementation for 3D data
	To compile: nvcc SDH.c -o SDH in the c4cuda machines
   ==================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>


#define BOX_SIZE	23000 /* size of the data box on one dimension            */

/* descriptors for single atom in the tree */
typedef struct atomdesc {
	double x_pos;
	double y_pos;
	double z_pos;
} atom;

typedef struct hist_entry{
	//float min;
	//float max;
	long long d_cnt;   /* need a long long type as the count might be huge */
} bucket;


bucket * histogram, * histogram2;		/* list of all buckets in the histogram   */
long long	PDH_acnt;	/* total number of data points            */
int num_buckets;		/* total number of buckets in the histogram */
double   PDH_res;		/* value of w                             */
atom * atom_list;		/* list of all data points                */

/* These are for an old way of tracking time */
struct timezone Idunno;	
struct timeval startTime, endTime;


/* 
	distance of two points in the atom_list for the CPU side
*/
double p2p_distance(int ind1, int ind2) {
	
	double x1 = atom_list[ind1].x_pos;
	double x2 = atom_list[ind2].x_pos;
	double y1 = atom_list[ind1].y_pos;
	double y2 = atom_list[ind2].y_pos;
	double z1 = atom_list[ind1].z_pos;
	double z2 = atom_list[ind2].z_pos;
		
	return sqrt((x1 - x2)*(x1-x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2));
}


/* 
	distance of two points in the atom_list for the GPU side 
*/
__device__
double p2p_distance_GPU(atom* d_atom_list, int ind1, int ind2) {
	
	double x1 = d_atom_list[ind1].x_pos;
	double x2 = d_atom_list[ind2].x_pos;
	double y1 = d_atom_list[ind1].y_pos;
	double y2 = d_atom_list[ind2].y_pos;
	double z1 = d_atom_list[ind1].z_pos;
	double z2 = d_atom_list[ind2].z_pos;
		
	return sqrt((x1 - x2)*(x1-x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2));
}


/* 
	brute-force SDH solution in a single CPU thread 
*/
int PDH_baseline() {
	int i, j, h_pos;
	double dist;
	
	for(i = 0; i < PDH_acnt; i++) {
		for(j = i+1; j < PDH_acnt; j++) {
			dist = p2p_distance(i,j);
			h_pos = (int) (dist / PDH_res);
			histogram[h_pos].d_cnt++;
		} 
	}
	return 0;
}

/* Implementation for GPU SDH function */
__global__
void GPU_baseline(bucket* d_histogram, atom* d_atom_list, double PDH_res, int PDH_acnt)
{
	//printf("\n###Hello from GPUn");
	int i= blockDim.x*blockIdx.x + threadIdx.x;
	int h_pos;
	//calculates unique global index
	//printf("i = %d \n", i);
	double dist;
	
	for(int j = i+1; j < PDH_acnt; j++) {
		dist = p2p_distance_GPU(d_atom_list, i,j);
		h_pos = (int) (dist / PDH_res);
		d_histogram[h_pos].d_cnt++;
	} 
}

/* 
	set a checkpoint and show the (natural) running time in seconds 
*/
double report_running_time() {
	long sec_diff, usec_diff;
	gettimeofday(&endTime, &Idunno);
	sec_diff = endTime.tv_sec - startTime.tv_sec;
	usec_diff= endTime.tv_usec-startTime.tv_usec;
	if(usec_diff < 0) {
		sec_diff --;
		usec_diff += 1000000;
	}
	printf("%ld.%06ld\n", sec_diff, usec_diff);
	return (double)(sec_diff*1.0 + usec_diff/1000000.0);
}


/* 
	print the counts in all buckets of the histogram 
*/
void output_histogram(){
	int i; 
	long long total_cnt = 0;
	for(i=0; i< num_buckets; i++) {
		if(i%5 == 0) /* we print 5 buckets in a row */
			printf("\n%02d: ", i);
		printf("%15lld ", histogram[i].d_cnt);
		total_cnt += histogram[i].d_cnt;
	  	/* we also want to make sure the total distance count is correct */
		if(i == num_buckets - 1)	
			printf("\n T:%lld \n", total_cnt);
		else printf("| ");
	}
}

/* 
	print the counts in all buckets of the histogram 
*/
void output_histogram2(){
	int i; 
	long long total_cnt = 0;
	for(i=0; i< num_buckets; i++) {
		if(i%5 == 0) /* we print 5 buckets in a row */
			printf("\n%02d: ", i);
		printf("%15lld ", histogram2[i].d_cnt);
		total_cnt += histogram2[i].d_cnt;
	  	/* we also want to make sure the total distance count is correct */
		if(i == num_buckets - 1)	
			printf("\n T:%lld \n", total_cnt);
		else printf("| ");
	}
}

void output_histogram_diff(bucket *histogram, bucket *histogram2){
	int i; 
	long long total_cnt = 0;
	for(i=0; i< num_buckets; i++) {
		if(i%5 == 0) /* we print 5 buckets in a row */
			printf("\n%02d: ", i);
		printf("%15lld ", histogram2[i].d_cnt - histogram[i].d_cnt);
		total_cnt += (histogram2[i].d_cnt - histogram[i].d_cnt);
	  	/* we also want to make sure the total distance count is correct */
		if(i == num_buckets - 1)	
			printf("\n T:%lld \n", total_cnt);
		else printf("| ");
	}
}



int main(int argc, char **argv)
{
	int i;

	PDH_acnt = atoi(argv[1]);
	PDH_res	 = atof(argv[2]);
//printf("args are %d and %f\n", PDH_acnt, PDH_res);

	num_buckets = (int)(BOX_SIZE * 1.732 / PDH_res) + 1;
	histogram = (bucket *)malloc(sizeof(bucket)*num_buckets);
	histogram2 = (bucket *)malloc(sizeof(bucket)*num_buckets);

	atom_list = (atom *)malloc(sizeof(atom)*PDH_acnt);

	
	srand(1);
	/* generate data following a uniform distribution */
	for(i = 0;  i < PDH_acnt; i++) {
		atom_list[i].x_pos = ((double)(rand()) / RAND_MAX) * BOX_SIZE;
		atom_list[i].y_pos = ((double)(rand()) / RAND_MAX) * BOX_SIZE;
		atom_list[i].z_pos = ((double)(rand()) / RAND_MAX) * BOX_SIZE;
	}
	/* start counting time */
	//gettimeofday(&startTime, &Idunno);
	
	/* call CPU single thread version to compute the histogram */
	PDH_baseline();
	
	/* print out the histogram */
	printf("\nCPU brute-force histogram\n");
	output_histogram();
	printf("\nGPU histogram\n");
	
	/* 
		### run time check commented out per instruction to only include histogram
		and differences between histograms ###
	*/  
	//printf("\nRunning time for CPU version: ");
	//report_running_time();
	
	/* ### BEGIN GPU VERSION ### */
	
	/* start counting time */
	//gettimeofday(&startTime, &Idunno);
	
	/* Allocate memory as shown in chapter 2.4 */
	bucket* d_histogram;
	atom* d_atom_list;
	
	cudaMalloc((void **) &d_histogram, sizeof(bucket)*num_buckets);
	cudaMemcpy(d_histogram, histogram, sizeof(bucket)*num_buckets, cudaMemcpyHostToDevice);
	
	cudaMalloc((void **) &d_atom_list, sizeof(atom)*PDH_acnt);
	cudaMemcpy(d_atom_list, atom_list, sizeof(atom)*PDH_acnt, cudaMemcpyHostToDevice);
	
	/* 
		call GPU version to complete histogram using execution config params per 2.5
		where <<<number of thread blocks, number of threads in each block>>>
	*/
	
	GPU_baseline <<<ceil(PDH_acnt/32), 32>>> (d_histogram, d_atom_list, PDH_res, PDH_acnt);
	
	/* transfer memory back to host per page 31 */
	cudaMemcpy(histogram2, d_histogram, sizeof(bucket)*num_buckets, cudaMemcpyHostToHost);
	
	/* Free memory as per chapter 2.4*/
	cudaFree(d_histogram);
	cudaFree(d_atom_list);
	
	/* 
		### run time check commented out per instruction to only include histogram
		and differences between histograms ###
	*/ 
	//printf("\nRunning time for GPU version: ");
	//report_running_time();
	
	/* print out the histogram */
	output_histogram2();
	
	printf("\nDifference between GPU histogram - CPU histogram\n");
	output_histogram_diff(histogram, histogram2);
	
	return 0;
}


