/*
 *	Garrett Moncrief
 *
 *	This program takes an input file with the employee name, id number, hrs worked, and hrly payrate
 *	and computes the net amount the employee has earned and the taxes taken out. This information is 
 *	then output to a .txt file. Futher comments on individual functions 
 */

#include <stdio.h>
#include "employee.h"

int main (int argc, char *argv[])
{
	FILE *fp;//for the input file 
	FILE *fw;//for the output file 
	
	int numEmp = 0; //keeps track of the number of employees from buildEmployeeList funct
	
	struct employee list [MAX_NUM_EMPLOYEES];
	
	//throws error message if incorrect number of inputs entered
	if (argc < 3)
	{
		printf ("\n\nUnable to Complete\n\nUsage: payroll <input filename> <output filename>\n\n");
		return 1;
	}
	
	//open files to r and w and prints error if unable to open
	if ((fp = fopen(argv[1], "r")) == NULL) 
	{
		fprintf (stderr, "\nCan't open %s\n", argv[1]);
		return 1;
	}
	
	if ((fw = fopen(argv[2], "w")) == NULL) 
	{
		fprintf (stderr, "\nCan't open %s\n", argv[2]);
		return 1;
	}
	
	printf ("\n\n###  Employee data read from \"%s\"  ###\n",argv[1]);
	
	//calls function to build the struct and also determine num of employees on input 
	numEmp = buildEmployeeList(fp, list);
	
	//calls function to write output file 
	writeSalaryInfoToFile(fw, list, numEmp);
	
	printf ("\n###  Payroll data written to \"%s\"  ###\n\n",argv[2]);
	
	fclose(fp);
	fclose(fw);
	
	return 0;
	
}