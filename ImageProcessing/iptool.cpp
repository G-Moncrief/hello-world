/************************************************************
 *															*
 * This sample project include three functions:				*
 * 1. Add intensity for gray-level image.					*
 *    Input: source image, output image name, value			*
 *															*
 * 2. Image thresholding: pixels will become black if the	*
 *    intensity is below the threshold, and white if above	*
 *    or equal the threhold.								*
 *    Input: source image, output image name, threshold		*
 *															*
 * 3. Image scaling: reduction/expansion of 2 for 			*
 *    the width and length. This project uses averaging 	*
 *    technique for reduction and pixel replication			*
 *    technique for expansion.								*
 *    Input: source image, output image name, scale factor	*
 *															*
 ************************************************************/

#include "./iptools/core.h"
#include <string.h>
#include <fstream>

using namespace std;

#define MAXLEN 256

int main(int argc, char** argv)
{
	image src, tgt;
	ifstream fp(argv[1]);
	char str[MAXLEN], str2[MAXLEN], str3[MAXLEN], str4[MAXLEN], str5[MAXLEN], str6[MAXLEN], str7[MAXLEN], str8[MAXLEN] , str9[MAXLEN], str10[MAXLEN];
	char T1[MAXLEN], T2[MAXLEN];
	rsize_t strmax = sizeof str;
	char outfile[MAXLEN];
	char *pch, *next_pch;
	int nOP;
	int nROI = 0;
	int roix = 0, roiy = 0, roisx = 0, roisy = 0,roix2 = 0,roiy2 = 0,roisx2 = 0,roisy2 = 0,roix3 = 0,roiy3 = 0,roisx3 = 0,roisy3 = 0;
	int val1 = 0, val2 = 0, val3 = 0, val4 = 0, val5 = 0, val6 = 0, val7 = 0, val8 = 0, val9 = 0;
	char rgb = 0, rgb2 = 0, rgb3 = 0;
	if (!fp.is_open()) {
		fprintf(stderr, "Can't open file: %s\n", argv[1]);
		exit(1);
	}

	fp >> nOP;
	for (int OP = 0; OP < nOP; OP++) {
		fp >> str;
		src.read(str);

		fp >> str;
		strcpy_s(outfile, MAXLEN, str);

		fp >> str;
		if (strncmp(str, "add", 3) == 0) {
			/* Add Intensity */
			fp >> str;
			utility::addGrey(src, tgt, atoi(str));
		}

        else if (strncmp(str,"binarize",8)==0) {
			/* Thresholding */
			fp >> T1;
			fp >> T2;
			utility::binarize(src,tgt,atoi(T1), atoi(T2));
		}

		else if (strncmp(str,"scale",5)==0) {
			/* Image scaling */
			fp >> str;
			utility::scale(src,tgt,atof(str));
		}

		else if (strncmp(str, "rgbmod", 6) == 0) {
			/* Color Intensity */
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; //ROI 1 params
			for (int i = 0; i < 3; i++) {
				fp >> str;
				if (strncmp(str, "dR", 2) == 0) fp >> str2;
				else if (strncmp(str, "dG", 2) == 0) fp >> str3;
				else if (strncmp(str, "dB", 2) == 0) fp >> str4;
				else std::cout << "\nSpecify dR, dG, and dB values for rgbmod.";
			}
			
			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; //ROI 2 params
				for (int i = 0; i < 3; i++) {
					fp >> str;
					if (strncmp(str, "dR", 2) == 0) fp >> str5;
					else if (strncmp(str, "dG", 2) == 0) fp >> str6;
					else if (strncmp(str, "dB", 2) == 0) fp >> str7;
					else std::cout << "\nSpecify dR, dG, and dB values for rgbmod.";
				}
			}
			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; //ROI 3 params
				for (int i = 0; i < 3; i++) {
					fp >> str;
					if (strncmp(str, "dR", 2) == 0) fp >> str8;
					else if (strncmp(str, "dG", 2) == 0) fp >> str9;
					else if (strncmp(str, "dB", 2) == 0) fp >> str10;
					else std::cout << "\nSpecify dR, dG, and dB values for rgbmod.";
				}
			} 
			
			
			utility::rgbmod(src, tgt, nROI, roix, roiy, roisx, roisy, atoi(str2), atoi(str3), atoi(str4), roix2, roiy2, roisx2, roisy2, atoi(str5), atoi(str6), atoi(str7), roix3, roiy3, roisx3, roisy3, atoi(str8), atoi(str9), atoi(str10));
		}

		else if (strncmp(str, "rgbbin", 6) == 0) {
			/* Color Binarization */
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; //ROI 1 params
			fp >> rgb;
			fp >> str;

			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; //ROI 2 params
				fp >> rgb2;
				fp >> str2;
			}

			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; //ROI 3 params
				fp >> rgb3;
				fp >> str3;
			}

			utility::rgbbin(src, tgt, nROI, roix, roiy, roisx, roisy, rgb, atoi(str), roix2, roiy2, roisx2, roisy2, rgb2, atoi(str2), roix3, roiy3, roisx3, roisy3, rgb3, atoi(str3));
		}

		else if (strncmp(str, "smooth2d", 8) == 0)
			/* 2D smooth*/
		{
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; //ROI 1 params
			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; //ROI 2 params
			}
			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; //ROI 3 params
			}
			utility::smooth2d(src, tgt, nROI, roix, roiy, roisx, roisy, roix2, roiy2, roisx2, roisy2, roix3, roiy3, roisx3, roisy3);
		}

		else if (strncmp(str, "incsmooth1d", 11) == 0)
		{
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; fp >> str; //ROI 1 params
			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; fp >> str2; //ROI 2 params
			}
			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; fp >> str3; //ROI 3 params
			}
			utility::incsmooth1d(src, tgt, nROI, roix, roiy, roisx, roisy, roix2, roiy2, roisx2, roisy2, roix3, roiy3, roisx3, roisy3);
		}

		else if (strncmp(str, "autothresh", 10) == 0)
		{
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; fp >> val1; fp >> val4; fp >> val7;//ROI 1 params
			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; fp >> val2; fp >> val5; fp >> val8;//ROI 2 params
			}
			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; fp >> val3; fp >> val6; fp >> val9; //ROI 3 params
			}
			utility::autothresh(src, tgt, nROI, roix, roiy, roisx, roisy, val1, val4, val7, roix2, roiy2, roisx2, roisy2, val2, val5, val8, roix3, roiy3, roisx3, roisy3, val3, val6, val9);
		}

		else if (strncmp(str, "rgbautothresh", 13) == 0)
		{
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; fp >> val1; //ROI 1 params
			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; fp >> val2; //ROI 2 params
			}
			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; fp >> val3; //ROI 3 params
			}
			utility::rgbautothresh(src, tgt, nROI, roix, roiy, roisx, roisy, val1, roix2, roiy2, roisx2, roisy2, val2, roix3, roiy3, roisx3, roisy3, val3);
		}

		else if (strncmp(str, "sobelint", 8) == 0)
		{
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; //ROI 1 params
			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; //ROI 2 params
			}
			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; //ROI 3 params
			}
			utility::sobelint(src, tgt, nROI, roix, roiy, roisx, roisy, roix2, roiy2, roisx2, roisy2, roix3, roiy3, roisx3, roisy3);
		}

		else if (strncmp(str, "sobelbw", 7) == 0)
		{
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; fp >> val1; //ROI 1 params
			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; fp >> val2; //ROI 2 params
			}
			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; fp >> val3; //ROI 3 params
			}
			utility::sobelbw(src, tgt, nROI, roix, roiy, roisx, roisy, val1, roix2, roiy2, roisx2, roisy2, val2, roix3, roiy3, roisx3, roisy3, val3);
		}

		else if (strncmp(str, "sobelang", 8) == 0)
		{
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; fp >> val1; //ROI 1 params
			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; fp >> val2; //ROI 2 params
			}
			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; fp >> val3; //ROI 3 params
			}
			utility::sobelang(src, tgt, nROI, roix, roiy, roisx, roisy, val1, roix2, roiy2, roisx2, roisy2, val2, roix3, roiy3, roisx3, roisy3, val3);
		}

		else if (strncmp(str, "sobelcolor", 10) == 0)
		{
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; fp >> val1; //ROI 1 params
			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; fp >> val2; //ROI 2 params
			}
			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; fp >> val3; //ROI 3 params
			}
			utility::sobelcolor(src, tgt, nROI, roix, roiy, roisx, roisy, val1, roix2, roiy2, roisx2, roisy2, val2, roix3, roiy3, roisx3, roisy3, val3);
		}

		else if (strncmp(str, "sobelhsi", 8) == 0)
		{
			fp >> nROI;
			fp >> roix; fp >> roiy; fp >> roisx; fp >> roisy; fp >> val1; //ROI 1 params
			if (nROI >= 2)
			{
				fp >> roix2; fp >> roiy2; fp >> roisx2; fp >> roisy2; fp >> val2; //ROI 2 params
			}
			if (nROI == 3)
			{
				fp >> roix3; fp >> roiy3; fp >> roisx3; fp >> roisy3; fp >> val3; //ROI 3 params
			}
			utility::sobelhsi(src, tgt, nROI, roix, roiy, roisx, roisy, val1, roix2, roiy2, roisx2, roisy2, val2, roix3, roiy3, roisx3, roisy3, val3);
		}

		else {
			printf("No function: %s\n", str);
			continue;
		}
       
		tgt.save(outfile);
	}
	//fclose(fp);
	fp.close();
	return 0;
}

