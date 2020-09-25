#include "utility.h"

#define MAXRGB 255
#define MINRGB 0
#define PI 3.141592653589793238462643383279

std::string utility::intToString(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int utility::checkValue(int value)
{
	if (value > MAXRGB)
		return MAXRGB;
	if (value < MINRGB)
		return MINRGB;
	return value;
}

/*-----------------------------------------------------------------------**/
void utility::addGrey(image &src, image &tgt, int value)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i=0; i<src.getNumberOfRows(); i++)
		for (int j=0; j<src.getNumberOfColumns(); j++)
		{
			tgt.setPixel(i,j,checkValue(src.getPixel(i,j)+value)); 
		}
}

/*-----------------------------------------------------------------------**/
void utility::binarize(image &src, image &tgt, int T1, int T2)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i=0; i<src.getNumberOfRows(); i++)
	{
		for (int j=0; j<src.getNumberOfColumns(); j++)
		{
			if (src.getPixel(i,j) < T1 || src.getPixel(i,j) > T2)
				tgt.setPixel(i,j,MINRGB);
			else
				tgt.setPixel(i,j,MAXRGB);
		}
	}
}

/*-----------------------------------------------------------------------**/
void utility::scale(image &src, image &tgt, float ratio)
{
	int rows = (int)((float)src.getNumberOfRows() * ratio);
	int cols  = (int)((float)src.getNumberOfColumns() * ratio);
	tgt.resize(rows, cols);
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{	
			/* Map the pixel of new image back to original image */
			int i2 = (int)floor((float)i/ratio);
			int j2 = (int)floor((float)j/ratio);
			if (ratio == 2) {
				/* Directly copy the value */
				tgt.setPixel(i,j,checkValue(src.getPixel(i2,j2)));
			}

			if (ratio == 0.5) {
				/* Average the values of four pixels */
				int value = src.getPixel(i2,j2) + src.getPixel(i2,j2+1) + src.getPixel(i2+1,j2) + src.getPixel(i2+1,j2+1);
				tgt.setPixel(i,j,checkValue(value/4));
			}
		}
	}
}

void utility::rgbmod(image &src, image &tgt,int nROI, int roix, int roiy, int roisx, int roisy, int rmod, int gmod, int bmod, int roix2, int roiy2, int roisx2, int roisy2, int rmod2, int gmod2, int bmod2, int roix3, int roiy3, int roisx3, int roisy3, int rmod3, int gmod3, int bmod3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());

	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				tgt.setPixel(i, j, RED, src.getPixel(i, j, RED) + rmod);
				tgt.setPixel(i, j, GREEN, src.getPixel(i, j, GREEN) + gmod);
				tgt.setPixel(i, j, BLUE, src.getPixel(i, j, BLUE) + bmod);
			}

			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				tgt.setPixel(i, j, RED, src.getPixel(i, j, RED) + rmod2);
				tgt.setPixel(i, j, GREEN, src.getPixel(i, j, GREEN) + gmod2);
				tgt.setPixel(i, j, BLUE, src.getPixel(i, j, BLUE) + bmod2);
			}

			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				tgt.setPixel(i, j, RED, src.getPixel(i, j, RED) + rmod3);
				tgt.setPixel(i, j, GREEN, src.getPixel(i, j, GREEN) + gmod3);
				tgt.setPixel(i, j, BLUE, src.getPixel(i, j, BLUE) + bmod3);
			}
			else
			{
				tgt.setPixel(i, j, RED, src.getPixel(i, j, RED));
				tgt.setPixel(i, j, GREEN, src.getPixel(i, j, GREEN));
				tgt.setPixel(i, j, BLUE, src.getPixel(i, j, BLUE));
			}
		}
	}
}

void utility::rgbbin(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int rgb, int T1, int roix2, int roiy2, int roisx2, int roisy2, int rgb2, int T2, int roix3, int roiy3, int roisx3, int roisy3, int rgb3, int T3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	int tarval = 0, tarval2 = 0, tarval3 = 0;

	if (rgb == 82) tarval = RED;
	else if (rgb == 71) tarval = GREEN;
	else if (rgb == 66) tarval = BLUE;

	if (rgb2 == 82) tarval2 = RED;
	else if (rgb2 == 71) tarval2 = GREEN;
	else if (rgb2 == 66) tarval2 = BLUE;

	if (rgb3 == 82) tarval3 = RED;
	else if (rgb3 == 71) tarval3 = GREEN;
	else if (rgb3 == 66) tarval3 = BLUE;

	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				if (src.getPixel(i, j, tarval) < T1)
				{
					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
				}
				else
				{
					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
				}
			}

			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				if (src.getPixel(i, j, tarval2) < T2)
				{
					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
				}
				else
				{
					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
				}
			}
			
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				if (src.getPixel(i, j, tarval3) < T3)
				{
					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
				}
				else
				{
					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
				}
			}
			else
			{
				tgt.setPixel(i, j, RED, src.getPixel(i, j, RED));
				tgt.setPixel(i, j, GREEN, src.getPixel(i, j, GREEN));
				tgt.setPixel(i, j, BLUE, src.getPixel(i, j, BLUE));
			}
		}
	}
}

void utility::smooth2d(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int roix2, int roiy2, int roisx2, int roisy2, int roix3, int roiy3, int roisx3, int roisy3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				/* Average the value of neighboring pixels*/
				int value = src.getPixel(i - 1, j - 1) + src.getPixel(i, j - 1) + src.getPixel(i + 1, j - 1) + src.getPixel(i - 1, j) + src.getPixel(i, j) + src.getPixel(i + 1, j) + src.getPixel(i - 1, j + 1) + src.getPixel(i, j + 1) + src.getPixel(i + 1, j + 1);
				tgt.setPixel(i, j, checkValue(value / 9));
			}
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				int value = src.getPixel(i - 1, j - 1) + src.getPixel(i, j - 1) + src.getPixel(i + 1, j - 1) + src.getPixel(i - 1, j) + src.getPixel(i, j) + src.getPixel(i + 1, j) + src.getPixel(i - 1, j + 1) + src.getPixel(i, j + 1) + src.getPixel(i + 1, j + 1);
				tgt.setPixel(i, j, checkValue(value / 9));
			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				int value = src.getPixel(i - 1, j - 1) + src.getPixel(i, j - 1) + src.getPixel(i + 1, j - 1) + src.getPixel(i - 1, j) + src.getPixel(i, j) + src.getPixel(i + 1, j) + src.getPixel(i - 1, j + 1) + src.getPixel(i, j + 1) + src.getPixel(i + 1, j + 1);
				tgt.setPixel(i, j, checkValue(value / 9));
			}
			else
				tgt.setPixel(i, j, src.getPixel(i, j));
			
		}
	}
}

void utility::incsmooth1d(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int roix2, int roiy2, int roisx2, int roisy2, int roix3, int roiy3, int roisx3, int roisy3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	int roi1xvalue = 0, roi2xvalue = 0, roi3xvalue = 0;
	int roi1yvalue = 0, roi2yvalue = 0, roi3yvalue = 0;
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				roi1xvalue = src.getPixel(i, j - 1) + src.getPixel(i, j) + src.getPixel(i, j + 1);
				roi1yvalue = src.getPixel(i - 1, j) + src.getPixel(i, j) + src.getPixel(i + 1, j);
				tgt.setPixel(i, j, checkValue((roi1yvalue + roi1xvalue)/6));
			}
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				roi2xvalue = src.getPixel(i, j - 1) + src.getPixel(i, j) + src.getPixel(i, j + 1);
				roi2yvalue = src.getPixel(i - 1, j) + src.getPixel(i, j) + src.getPixel(i + 1, j);
				tgt.setPixel(i, j, checkValue((roi2yvalue + roi2xvalue) / 6));
			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				roi3xvalue = src.getPixel(i, j - 1) + src.getPixel(i, j) + src.getPixel(i, j + 1);
				roi3yvalue = src.getPixel(i - 1, j) + src.getPixel(i, j) + src.getPixel(i + 1, j);
				tgt.setPixel(i, j, checkValue((roi3yvalue + roi3xvalue) / 6));
			}
			else
				tgt.setPixel(i, j, src.getPixel(i, j));
		}
	}
}

void utility::autothresh(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int limit1, int target1, int smooth1, int roix2, int roiy2, int roisx2, int roisy2, int limit2, int target2, int smooth2, int roix3, int roiy3, int roisx3, int roisy3, int limit3, int target3, int smooth3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	
	int thresh1 = 0, thresh2 = 0, thresh3 = 0, bgval = 0, fgval = 0;
	int count1 = 0, count2 = 0, count3 = 0, bgcount = 0, fgcount = 0;
	
	//get initial threshold value for ROIs if user entered 0 for threshold
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)) && limit1 == 0)
			{
				thresh1 += src.getPixel(i, j);
				count1++;
			}
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)) && limit2 == 0)
			{
				thresh2 += src.getPixel(i, j);
				count2++;
			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)) && limit3 == 0)
			{
				thresh3 += src.getPixel(i, j);
				count3++;
			}
		}
	}
	//otherwise use user specified threshold
	if (limit1 == 0) thresh1 = thresh1 / count1; else thresh1 = limit1;
	if (limit2 == 0) thresh2 = thresh2 / count2; else thresh2 = limit2;
	if (limit3 == 0) thresh3 = thresh3 / count3; else thresh3 = limit3;

	std::cout << thresh1 << "\t" << thresh2 << "\t" << thresh3 << "\n";

	do
	{
		for (int i = 0; i < src.getNumberOfRows(); i++)
		{
			for (int j = 0; j < src.getNumberOfColumns(); j++)
			{
				if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
				{
					if (src.getPixel(i, j) < thresh1)
					{
						bgval += src.getPixel(i, j);
						bgcount++;
					}
						
					else
					{
						fgval += src.getPixel(i, j);
						fgcount++;
					}
				}
			}
		}
		if ((thresh1 - (((bgval / bgcount) + (fgval / fgcount)/2))) < target1)
		{
			thresh1 = (((bgval / bgcount) + (fgval / fgcount)) / 2);
			break;
		}

	} while (target1 < thresh1);
	bgval = 0.0; bgcount = 0; fgval = 0.0; fgcount = 0; //reset counts
	do
	{
		for (int i = 0; i < src.getNumberOfRows(); i++)
		{
			for (int j = 0; j < src.getNumberOfColumns(); j++)
			{
				if (((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
				{
					if (src.getPixel(i, j) < thresh2)
					{
						bgval += src.getPixel(i, j);
						bgcount++;
					}

					else
					{
						fgval += src.getPixel(i, j);
						fgcount++;
					}
				}
			}
		}
		if ((thresh2 - (((bgval / bgcount) + (fgval / fgcount) / 2))) < target2)
		{
			thresh2 = (((bgval / bgcount) + (fgval / fgcount)) / 2);
			break;
		}

	} while (target2 < thresh2);
	bgval = 0.0; bgcount = 0; fgval = 0.0; fgcount = 0; //reset counts
	do
	{
		for (int i = 0; i < src.getNumberOfRows(); i++)
		{
			for (int j = 0; j < src.getNumberOfColumns(); j++)
			{
				if (((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
				{
					if (src.getPixel(i, j) < thresh3)
					{
						bgval += src.getPixel(i, j);
						bgcount++;
					}

					else
					{
						fgval += src.getPixel(i, j);
						fgcount++;
					}
				}
			}
		}
		if ((thresh3 - (((bgval / bgcount) + (fgval / fgcount) / 2))) < target3)
		{
			thresh3 = (((bgval / bgcount) + (fgval / fgcount)) / 2);
			break;
		}

	} while (target3 < thresh3);

	std::cout << thresh1 << "\t" << thresh2 << "\t" << thresh3 << "\n";
	
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				if (src.getPixel(i, j) < thresh1)
					tgt.setPixel(i, j, MINRGB);
				else
					tgt.setPixel(i, j, MAXRGB);
			}
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				if (src.getPixel(i, j) < thresh2)
					tgt.setPixel(i, j, MINRGB);
				else
					tgt.setPixel(i, j, MAXRGB);
			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				if (src.getPixel(i, j) < thresh3)
					tgt.setPixel(i, j, MINRGB);
				else
					tgt.setPixel(i, j, MAXRGB);
			}
			else
				tgt.setPixel(i, j, src.getPixel(i, j));
		}
	}
}

void utility::rgbautothresh(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int hsi, int roix2, int roiy2, int roisx2, int roisy2, int hsi2, int roix3, int roiy3, int roisx3, int roisy3, int hsi3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());

	float R = 0, G = 0, B = 0, total1 = 0, total2 = 0, total3 = 0;
	int count1 = 0, count2 = 0, count3 = 0;

	//convert to HSI and find thresholding
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				R = float((src.getPixel(i, j, RED)));
				G = float((src.getPixel(i, j, GREEN)));
				B = float((src.getPixel(i, j, BLUE)));
				double r = R / (R + G + B);
				double g = G / (R + G + B);
				double b = B / (R + G + B);

				double h = 0.0; //find h
				if (b > g)
					h = ((2 * PI) - acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));
				else
					h = (acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));

				double s = 0.0; //find s
				if (r < g && r < b)
					s = 1 - (3 * r);
				else if (b < r && b < g)
					s = 1 - (3 * b);
				else
					s = 1 - (3 * g);

				double intensity = (R + G + B) / (3 * 255);

				int H = (h *180)/PI;
				int S = s * 100;
				int I = ((R + G + B) / (3 * 255)) * 255;

				if (hsi == 1)
				{
					total1 += H;
					count1++;
				}

				if (hsi == 2)
				{
					total1 += S;
					count1++;
				}

				if (hsi == 3)
				{
					total1 += I;
					count1++;
				}
				
				//std::cout << x << "\t" << y << "\t" << z << "\t" << r*255 << "\t" << b*255 << "\t" << g*255 << "\t" << "\n";

				//std::cout << H << "\t" << S << "\t" << I << "\n";
			}
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				R = float((src.getPixel(i, j, RED)));
				G = float((src.getPixel(i, j, GREEN)));
				B = float((src.getPixel(i, j, BLUE)));
				double r = R / (R + G + B);
				double g = G / (R + G + B);
				double b = B / (R + G + B);

				double h = 0.0; //find h
				if (b > g)
					h = ((2 * PI) - acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));
				else
					h = (acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));

				double s = 0.0; //find s
				if (r < g && r < b)
					s = 1 - (3 * r);
				else if (b < r && b < g)
					s = 1 - (3 * b);
				else
					s = 1 - (3 * g);

				double intensity = (R + G + B) / (3 * 255);

				int H = (h * 180) / PI;
				int S = s * 100;
				int I = ((R + G + B) / (3 * 255)) * 255;

				if (hsi2 == 1)
				{
					total2 += H;
					count2++;
				}

				if (hsi2 == 2)
				{
					total2 += S;
					count2++;
				}

				if (hsi2 == 3)
				{
					total2 += I;
					count2++;
				}
			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				R = float((src.getPixel(i, j, RED)));
				G = float((src.getPixel(i, j, GREEN)));
				B = float((src.getPixel(i, j, BLUE)));
				double r = R / (R + G + B);
				double g = G / (R + G + B);
				double b = B / (R + G + B);

				double h = 0.0; //find h
				if (b > g)
					h = ((2 * PI) - acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));
				else
					h = (acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));

				double s = 0.0; //find s
				if (r < g && r < b)
					s = 1 - (3 * r);
				else if (b < r && b < g)
					s = 1 - (3 * b);
				else
					s = 1 - (3 * g);

				double intensity = (R + G + B) / (3 * 255);

				int H = (h * 180) / PI;
				int S = s * 100;
				int I = ((R + G + B) / (3 * 255)) * 255;

				if (hsi3 == 1)
				{
					total3 += H;
					count3++;
				}

				if (hsi3 == 2)
				{
					total3 += S;
					count3++;
				}

				if (hsi3 == 3)
				{
					total3 += I;
					count3++;
				}
			}
		}
	}
	//std::cout << total1 / count1;
	//apply thresholding
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				R = float((src.getPixel(i, j, RED)));
				G = float((src.getPixel(i, j, GREEN)));
				B = float((src.getPixel(i, j, BLUE)));
				double r = R / (R + G + B);
				double g = G / (R + G + B);
				double b = B / (R + G + B);

				double h = 0.0; //find h
				if (b > g)
					h = ((2 * PI) - acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));
				else
					h = (acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));

				double s = 0.0; //find s
				if (r < g && r < b)
					s = 1 - (3 * r);
				else if (b < r && b < g)
					s = 1 - (3 * b);
				else
					s = 1 - (3 * g);

				double intensity = (R + G + B) / (3 * 255);

				int H = (h * 180) / PI;
				int S = s * 100;
				int I = ((R + G + B) / (3 * 255)) * 255;

				double x = float(intensity) * (1 - s);
				double y = (intensity) * (1 + ((s*cos(h)) / cos(PI / (3 - PI))));
				double z = (3 * (intensity)) - (x + y);

				if (h < (2 * PI / 3))
				{
					b = x; r = y; g = z;
				}
				else if (((2 * PI) / 3) <= h < ((4 * PI / 3)))
				{
					r = x; g = y; b = z;
				}
				else
				{
					g = x; b = y; r = z;
				}

				tgt.setPixel(i, j, RED, r * 255);
				tgt.setPixel(i, j, GREEN, g * 255);
				tgt.setPixel(i, j, BLUE, b * 255);
				//std::cout << x << "\t" << y << "\t" << z << "\t" << r*255 << "\t" << b*255 << "\t" << g*255 << "\t" << "\n";

				if (hsi == 1)
				{
					if (H < (total1 / count1))
					{
						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);
					}
					else
					{
						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}

				if (hsi == 2)
				{
					if (S < (total1 / count1))
					{
						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);
					}
					else
					{
						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}

				if (hsi == 3)
				{
					if (I < (total1 / count1))
					{
						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);
					}
					else
					{
						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}

				//std::cout << H << "\t" << S << "\t" << I << "\n";
			}
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				R = float((src.getPixel(i, j, RED)));
				G = float((src.getPixel(i, j, GREEN)));
				B = float((src.getPixel(i, j, BLUE)));
				double r = R / (R + G + B);
				double g = G / (R + G + B);
				double b = B / (R + G + B);

				double h = 0.0; //find h
				if (b > g)
					h = ((2 * PI) - acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));
				else
					h = (acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));

				double s = 0.0; //find s
				if (r < g && r < b)
					s = 1 - (3 * r);
				else if (b < r && b < g)
					s = 1 - (3 * b);
				else
					s = 1 - (3 * g);

				double intensity = (R + G + B) / (3 * 255);

				int H = (h * 180) / PI;
				int S = s * 100;
				int I = ((R + G + B) / (3 * 255)) * 255;

				double x = float(intensity) * (1 - s);
				double y = (intensity) * (1 + ((s*cos(h)) / cos(PI / (3 - PI))));
				double z = (3 * (intensity)) - (x + y);

				if (h < (2 * PI / 3))
				{
					b = x; r = y; g = z;
				}
				else if (((2 * PI) / 3) <= h < ((4 * PI / 3)))
				{
					r = x; g = y; b = z;
				}
				else
				{
					g = x; b = y; r = z;
				}

				tgt.setPixel(i, j, RED, r * 255);
				tgt.setPixel(i, j, GREEN, g * 255);
				tgt.setPixel(i, j, BLUE, b * 255);
				//std::cout << x << "\t" << y << "\t" << z << "\t" << r*255 << "\t" << b*255 << "\t" << g*255 << "\t" << "\n";

				if (hsi2 == 1)
				{
					if (H < (total2 / count2))
					{
						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);
					}
					else
					{
						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}

				if (hsi2 == 2)
				{
					if (S < (total2 / count2))
					{
						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);
					}
					else
					{
						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}

				if (hsi2 == 3)
				{
					if (I < (total2 / count2))
					{
						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);
					}
					else
					{
						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}

				//std::cout << H << "\t" << S << "\t" << I << "\n";
			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				R = float((src.getPixel(i, j, RED)));
				G = float((src.getPixel(i, j, GREEN)));
				B = float((src.getPixel(i, j, BLUE)));
				double r = R / (R + G + B);
				double g = G / (R + G + B);
				double b = B / (R + G + B);

				double h = 0.0; //find h
				if (b > g)
					h = ((2 * PI) - acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));
				else
					h = (acos((0.5*((r - g) + (r - b))) / (pow(pow(r - g, 2) + (r - b)*(g - b), 0.5))));

				double s = 0.0; //find s
				if (r < g && r < b)
					s = 1 - (3 * r);
				else if (b < r && b < g)
					s = 1 - (3 * b);
				else
					s = 1 - (3 * g);

				double intensity = (R + G + B) / (3 * 255);

				int H = (h * 180) / PI;
				int S = s * 100;
				int I = ((R + G + B) / (3 * 255)) * 255;

				double x = float(intensity) * (1 - s);
				double y = (intensity) * (1 + ((s*cos(h)) / cos(PI / (3 - PI))));
				double z = (3 * (intensity)) - (x + y);

				if (h < (2 * PI / 3))
				{
					b = x; r = y; g = z;
				}
				else if (((2 * PI) / 3) <= h < ((4 * PI / 3)))
				{
					r = x; g = y; b = z;
				}
				else
				{
					g = x; b = y; r = z;
				}

				tgt.setPixel(i, j, RED, r * 255);
				tgt.setPixel(i, j, GREEN, g * 255);
				tgt.setPixel(i, j, BLUE, b * 255);
				//std::cout << x << "\t" << y << "\t" << z << "\t" << r*255 << "\t" << b*255 << "\t" << g*255 << "\t" << "\n";

				if (hsi3 == 1)
				{
					if (H < (total3 / count3))
					{
						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);
					}
					else
					{
						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}

				if (hsi3 == 2)
				{
					if (S < (total3 / count3))
					{
						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);
					}
					else
					{
						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}

				if (hsi3 == 3)
				{
					if (I < (total3 / count3))
					{
						tgt.setPixel(i, j, RED, MINRGB);
						tgt.setPixel(i, j, GREEN, MINRGB);
						tgt.setPixel(i, j, BLUE, MINRGB);
					}
					else
					{
						tgt.setPixel(i, j, RED, MAXRGB);
						tgt.setPixel(i, j, GREEN, MAXRGB);
						tgt.setPixel(i, j, BLUE, MAXRGB);
					}
				}

				//std::cout << H << "\t" << S << "\t" << I << "\n";
			}
			else
			{
				tgt.setPixel(i, j, RED, src.getPixel(i, j, RED));
				tgt.setPixel(i, j, GREEN, src.getPixel(i, j, GREEN));
				tgt.setPixel(i, j, BLUE, src.getPixel(i, j, BLUE));
			}
		}
	}
}

// ASSIGNMENT 3 STUFF BELOW

void utility::sobelint(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int roix2, int roiy2, int roisx2, int roisy2, int roix3, int roiy3, int roisx3, int roisy3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				int gx = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j + 1)) //gx top row
					+ (src.getPixel(i, j - 1) * -2) + (src.getPixel(i, j + 2) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1) * -1) + (src.getPixel(i + 1, j + 1))); // gx bottom row

				int gy = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j) * -2) + (src.getPixel(i - 1, j + 1) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1) * 1) + (src.getPixel(i + 1, j) * 2) + (src.getPixel(i + 1, j + 1))); // gy bottom row

				int G = sqrt((gx*gx) + (gy*gy));
				//std::cout << gx << "\t" << gy << "\t" << G << "\n"; //testing

				tgt.setPixel(i, j, G);

			}
			
			
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				int gx = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j + 1)) //gx top row
					+ (src.getPixel(i, j - 1) * -2) + (src.getPixel(i, j + 2) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1) * -1) + (src.getPixel(i + 1, j + 1))); // gx bottom row

				int gy = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j) * -2) + (src.getPixel(i - 1, j + 1) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1) * 1) + (src.getPixel(i + 1, j) * 2) + (src.getPixel(i + 1, j + 1))); // gy bottom row

				int G = sqrt((gx*gx) + (gy*gy));
				//std::cout << gx << "\t" << gy << "\t" << G << "\n"; //testing

				tgt.setPixel(i, j, G);
			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				int gx = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j + 1)) //gx top row
					+ (src.getPixel(i, j - 1) * -2) + (src.getPixel(i, j + 2) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1) * -1) + (src.getPixel(i + 1, j + 1))); // gx bottom row

				int gy = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j) * -2) + (src.getPixel(i - 1, j + 1) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1) * 1) + (src.getPixel(i + 1, j) * 2) + (src.getPixel(i + 1, j + 1))); // gy bottom row

				int G = sqrt((gx*gx) + (gy*gy));
				//std::cout << gx << "\t" << gy << "\t" << G << "\n"; //testing

				tgt.setPixel(i, j, G);
			}
			else
				tgt.setPixel(i, j, src.getPixel(i, j));
		}
	}
}

void utility::sobelbw(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int t1, int roix2, int roiy2, int roisx2, int roisy2, int t2, int roix3, int roiy3, int roisx3, int roisy3, int t3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				int gx = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j + 1)) //gx top row
					+ (src.getPixel(i, j - 1) * -2) + (src.getPixel(i, j + 2) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1) * -1) + (src.getPixel(i + 1, j + 1))); // gx bottom row
				
				int gy = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j) * -2) + (src.getPixel(i - 1, j + 1) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1) * 1) + (src.getPixel(i + 1, j) * 2) + (src.getPixel(i + 1, j + 1))); // gy bottom row

				int G = sqrt((gx*gx)+(gy*gy));
				//std::cout << gx << "\t" << gy << "\t" << G << "\n"; //testing


				if (G < t1)
					tgt.setPixel(i, j, MINRGB);
				else
					tgt.setPixel(i, j, MAXRGB);
			}
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				int gx = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j + 1)) //gx top row
					+ (src.getPixel(i, j - 1) * -2) + (src.getPixel(i, j + 2) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1) * -1) + (src.getPixel(i + 1, j + 1))); // gx bottom row

				int gy = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j) * -2) + (src.getPixel(i - 1, j + 1) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1) * 1) + (src.getPixel(i + 1, j) * 2) + (src.getPixel(i + 1, j + 1))); // gy bottom row

				int G = sqrt((gx*gx) + (gy*gy));
				//std::cout << gx << "\t" << gy << "\t" << G << "\n"; //testing


				if (G < t2)
					tgt.setPixel(i, j, MINRGB);
				else
					tgt.setPixel(i, j, MAXRGB);
			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				int gx = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j + 1)) //gx top row
					+ (src.getPixel(i, j - 1) * -2) + (src.getPixel(i, j + 2) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1) * -1) + (src.getPixel(i + 1, j + 1))); // gx bottom row

				int gy = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j) * -2) + (src.getPixel(i - 1, j + 1) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1) * 1) + (src.getPixel(i + 1, j) * 2) + (src.getPixel(i + 1, j + 1))); // gy bottom row

				int G = sqrt((gx*gx) + (gy*gy));
				//std::cout << gx << "\t" << gy << "\t" << G << "\n"; //testing


				if (G < t3)
					tgt.setPixel(i, j, MINRGB);
				else
					tgt.setPixel(i, j, MAXRGB);
			}
			else
				tgt.setPixel(i, j, src.getPixel(i, j));
		}
	}
}

void utility::sobelang(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int t1, int roix2, int roiy2, int roisx2, int roisy2, int t2, int roix3, int roiy3, int roisx3, int roisy3, int t3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				int gx = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j + 1)) //gx top row
					+ (src.getPixel(i, j - 1) * -2) + (src.getPixel(i, j + 2) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1) * -1) + (src.getPixel(i + 1, j + 1))); // gx bottom row

				int gy = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j) * -2) + (src.getPixel(i - 1, j + 1) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1) * 1) + (src.getPixel(i + 1, j) * 2) + (src.getPixel(i + 1, j + 1))); // gy bottom row

				tgt.setPixel(i, j, src.getPixel(i, j));

				double G = 0;

				if (gx != 0) //this prevents a divide by zero exception 
					 G = (atan(gy/gx)*180)/PI;

				if ((G <= t1 + 10) && (G >= t1-10))
					tgt.setPixel(i, j, MINRGB);
				else
					tgt.setPixel(i, j, MAXRGB);

				//std::cout << gx << "\t" << gy << "\t" << G << "\n"; //testing
			}
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				int gx = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j + 1)) //gx top row
					+ (src.getPixel(i, j - 1) * -2) + (src.getPixel(i, j + 2) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1) * -1) + (src.getPixel(i + 1, j + 1))); // gx bottom row

				int gy = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j) * -2) + (src.getPixel(i - 1, j + 1) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1) * 1) + (src.getPixel(i + 1, j) * 2) + (src.getPixel(i + 1, j + 1))); // gy bottom row

				double G = 0;

				if (gx != 0)
					G = (atan(gy / gx) * 180) / PI;

				if ((G <= t1 + 10) && (G >= t2 - 10))
					tgt.setPixel(i, j, MINRGB);
				else
					tgt.setPixel(i, j, MAXRGB);

				//std::cout << gx << "\t" << gy << "\t" << G << "\n"; //testing
			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				int gx = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j + 1)) //gx top row
					+ (src.getPixel(i, j - 1) * -2) + (src.getPixel(i, j + 2) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1) * -1) + (src.getPixel(i + 1, j + 1))); // gx bottom row

				int gy = ((src.getPixel(i - 1, j - 1) * -1) + (src.getPixel(i - 1, j) * -2) + (src.getPixel(i - 1, j + 1) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1) * 1) + (src.getPixel(i + 1, j) * 2) + (src.getPixel(i + 1, j + 1))); // gy bottom row

				tgt.setPixel(i, j, src.getPixel(i, j));

				double G = 0;

				if (gx != 0)
					G = (atan(gy / gx) * 180) / PI;

				if ((G <= t1 + 10) && (G >= t3 - 10))
					tgt.setPixel(i, j, MINRGB);
				else
					tgt.setPixel(i, j, MAXRGB);

				//std::cout << gx << "\t" << gy << "\t" << G << "\n"; //testing
			}
			else
				tgt.setPixel(i, j, src.getPixel(i, j));
		}
	}
}

void utility::sobelcolor(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int t1, int roix2, int roiy2, int roisx2, int roisy2, int t2, int roix3, int roiy3, int roisx3, int roisy3, int t3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{

			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				int gxRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j + 1, RED)) //gx top row
					+ (src.getPixel(i, j - 1, RED) * -2) + (src.getPixel(i, j + 2, RED) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, RED) * -1) + (src.getPixel(i + 1, j + 1, RED))); // gx bottom row

				int gyRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j, RED) * -2) + (src.getPixel(i - 1, j + 1, RED) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, RED) * 1) + (src.getPixel(i + 1, j, RED) * 2) + (src.getPixel(i + 1, j + 1, RED))); // gy bottom row

				int GRED = sqrt((gxRED*gxRED) + (gyRED*gyRED));

				int gxBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j + 1, BLUE)) //gx top row
					+ (src.getPixel(i, j - 1, BLUE) * -2) + (src.getPixel(i, j + 2, BLUE) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, BLUE) * -1) + (src.getPixel(i + 1, j + 1, BLUE))); // gx bottom row

				int gyBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j, BLUE) * -2) + (src.getPixel(i - 1, j + 1, BLUE) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, BLUE) * 1) + (src.getPixel(i + 1, j, BLUE) * 2) + (src.getPixel(i + 1, j + 1, BLUE))); // gy bottom row

				int GBLUE = sqrt((gxBLUE*gxBLUE) + (gyBLUE*gyBLUE));

				int gxGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j + 1, GREEN)) //gx top row
					+ (src.getPixel(i, j - 1, GREEN) * -2) + (src.getPixel(i, j + 2, GREEN) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, GREEN) * -1) + (src.getPixel(i + 1, j + 1, GREEN))); // gx bottom row

				int gyGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j, GREEN) * -2) + (src.getPixel(i - 1, j + 1, GREEN) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, GREEN) * 1) + (src.getPixel(i + 1, j, GREEN) * 2) + (src.getPixel(i + 1, j + 1, GREEN))); // gy bottom row

				int GGREEN = sqrt((gxGREEN*gxGREEN) + (gyGREEN*gyGREEN));

				if (GRED < t1 || GBLUE < t1 || GGREEN < t1)
				{
					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
				}
				else
				{
					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
				}
			}
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				int gxRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j + 1, RED)) //gx top row
					+ (src.getPixel(i, j - 1, RED) * -2) + (src.getPixel(i, j + 2, RED) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, RED) * -1) + (src.getPixel(i + 1, j + 1, RED))); // gx bottom row

				int gyRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j, RED) * -2) + (src.getPixel(i - 1, j + 1, RED) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, RED) * 1) + (src.getPixel(i + 1, j, RED) * 2) + (src.getPixel(i + 1, j + 1, RED))); // gy bottom row

				int GRED = sqrt((gxRED*gxRED) + (gyRED*gyRED));

				int gxBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j + 1, BLUE)) //gx top row
					+ (src.getPixel(i, j - 1, BLUE) * -2) + (src.getPixel(i, j + 2, BLUE) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, BLUE) * -1) + (src.getPixel(i + 1, j + 1, BLUE))); // gx bottom row

				int gyBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j, BLUE) * -2) + (src.getPixel(i - 1, j + 1, BLUE) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, BLUE) * 1) + (src.getPixel(i + 1, j, BLUE) * 2) + (src.getPixel(i + 1, j + 1, BLUE))); // gy bottom row

				int GBLUE = sqrt((gxBLUE*gxBLUE) + (gyBLUE*gyBLUE));

				int gxGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j + 1, GREEN)) //gx top row
					+ (src.getPixel(i, j - 1, GREEN) * -2) + (src.getPixel(i, j + 2, GREEN) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, GREEN) * -1) + (src.getPixel(i + 1, j + 1, GREEN))); // gx bottom row

				int gyGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j, GREEN) * -2) + (src.getPixel(i - 1, j + 1, GREEN) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, GREEN) * 1) + (src.getPixel(i + 1, j, GREEN) * 2) + (src.getPixel(i + 1, j + 1, GREEN))); // gy bottom row

				int GGREEN = sqrt((gxGREEN*gxGREEN) + (gyGREEN*gyGREEN));

				if (GRED < t2 || GBLUE < t2 || GGREEN < t2)
				{
					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
				}
				else
				{
					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
				}

			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				int gxRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j + 1, RED)) //gx top row
					+ (src.getPixel(i, j - 1, RED) * -2) + (src.getPixel(i, j + 2, RED) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, RED) * -1) + (src.getPixel(i + 1, j + 1, RED))); // gx bottom row

				int gyRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j, RED) * -2) + (src.getPixel(i - 1, j + 1, RED) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, RED) * 1) + (src.getPixel(i + 1, j, RED) * 2) + (src.getPixel(i + 1, j + 1, RED))); // gy bottom row

				int GRED = sqrt((gxRED*gxRED) + (gyRED*gyRED));

				int gxBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j + 1, BLUE)) //gx top row
					+ (src.getPixel(i, j - 1, BLUE) * -2) + (src.getPixel(i, j + 2, BLUE) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, BLUE) * -1) + (src.getPixel(i + 1, j + 1, BLUE))); // gx bottom row

				int gyBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j, BLUE) * -2) + (src.getPixel(i - 1, j + 1, BLUE) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, BLUE) * 1) + (src.getPixel(i + 1, j, BLUE) * 2) + (src.getPixel(i + 1, j + 1, BLUE))); // gy bottom row

				int GBLUE = sqrt((gxBLUE*gxBLUE) + (gyBLUE*gyBLUE));

				int gxGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j + 1, GREEN)) //gx top row
					+ (src.getPixel(i, j - 1, GREEN) * -2) + (src.getPixel(i, j + 2, GREEN) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, GREEN) * -1) + (src.getPixel(i + 1, j + 1, GREEN))); // gx bottom row

				int gyGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j, GREEN) * -2) + (src.getPixel(i - 1, j + 1, GREEN) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, GREEN) * 1) + (src.getPixel(i + 1, j, GREEN) * 2) + (src.getPixel(i + 1, j + 1, GREEN))); // gy bottom row

				int GGREEN = sqrt((gxGREEN*gxGREEN) + (gyGREEN*gyGREEN));

				if (GRED < t3 || GBLUE < t3 || GGREEN < t3)
				{
					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
				}
				else
				{
					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
				}

			}
			else
			{
				tgt.setPixel(i, j, RED, src.getPixel(i, j, RED));
				tgt.setPixel(i, j, GREEN, src.getPixel(i, j, GREEN));
				tgt.setPixel(i, j, BLUE, src.getPixel(i, j, BLUE));
			}
		}
	}
}

void utility::sobelhsi(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int t1, int roix2, int roiy2, int roisx2, int roisy2, int t2, int roix3, int roiy3, int roisx3, int roisy3, int t3)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());

	for (int i = 0; i < src.getNumberOfRows(); i++)
	{
		for (int j = 0; j < src.getNumberOfColumns(); j++)
		{
			if (((i > roiy - roisy) && (i < roiy + roisy)) && ((j > roix - roisx) && (j < roix + roisx)))
			{
				int gxRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j + 1, RED)) //gx top row
					+ (src.getPixel(i, j - 1, RED) * -2) + (src.getPixel(i, j + 2, RED) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, RED) * -1) + (src.getPixel(i + 1, j + 1, RED))); // gx bottom row

				int gyRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j, RED) * -2) + (src.getPixel(i - 1, j + 1, RED) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, RED) * 1) + (src.getPixel(i + 1, j, RED) * 2) + (src.getPixel(i + 1, j + 1, RED))); // gy bottom row

				int GRED = sqrt((gxRED*gxRED) + (gyRED*gyRED));

				int gxBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j + 1, BLUE)) //gx top row
					+ (src.getPixel(i, j - 1, BLUE) * -2) + (src.getPixel(i, j + 2, BLUE) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, BLUE) * -1) + (src.getPixel(i + 1, j + 1, BLUE))); // gx bottom row

				int gyBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j, BLUE) * -2) + (src.getPixel(i - 1, j + 1, BLUE) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, BLUE) * 1) + (src.getPixel(i + 1, j, BLUE) * 2) + (src.getPixel(i + 1, j + 1, BLUE))); // gy bottom row

				int GBLUE = sqrt((gxBLUE*gxBLUE) + (gyBLUE*gyBLUE));

				int gxGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j + 1, GREEN)) //gx top row
					+ (src.getPixel(i, j - 1, GREEN) * -2) + (src.getPixel(i, j + 2, GREEN) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, GREEN) * -1) + (src.getPixel(i + 1, j + 1, GREEN))); // gx bottom row

				int gyGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j, GREEN) * -2) + (src.getPixel(i - 1, j + 1, GREEN) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, GREEN) * 1) + (src.getPixel(i + 1, j, GREEN) * 2) + (src.getPixel(i + 1, j + 1, GREEN))); // gy bottom row

				int GGREEN = sqrt((gxGREEN*gxGREEN) + (gyGREEN*gyGREEN));

				int I = ((GRED + GBLUE + GGREEN) / 3);


				if (I < t1)
				{
					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
				}
				else
				{
					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
				}
			}
			else if ((nROI >= 2) && ((i > roiy2 - roisy2) && (i < roiy2 + roisy2)) && ((j > roix2 - roisx2) && (j < roix2 + roisx2)))
			{
				int gxRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j + 1, RED)) //gx top row
					+ (src.getPixel(i, j - 1, RED) * -2) + (src.getPixel(i, j + 2, RED) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, RED) * -1) + (src.getPixel(i + 1, j + 1, RED))); // gx bottom row

				int gyRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j, RED) * -2) + (src.getPixel(i - 1, j + 1, RED) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, RED) * 1) + (src.getPixel(i + 1, j, RED) * 2) + (src.getPixel(i + 1, j + 1, RED))); // gy bottom row

				int GRED = sqrt((gxRED*gxRED) + (gyRED*gyRED));

				int gxBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j + 1, BLUE)) //gx top row
					+ (src.getPixel(i, j - 1, BLUE) * -2) + (src.getPixel(i, j + 2, BLUE) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, BLUE) * -1) + (src.getPixel(i + 1, j + 1, BLUE))); // gx bottom row

				int gyBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j, BLUE) * -2) + (src.getPixel(i - 1, j + 1, BLUE) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, BLUE) * 1) + (src.getPixel(i + 1, j, BLUE) * 2) + (src.getPixel(i + 1, j + 1, BLUE))); // gy bottom row

				int GBLUE = sqrt((gxBLUE*gxBLUE) + (gyBLUE*gyBLUE));

				int gxGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j + 1, GREEN)) //gx top row
					+ (src.getPixel(i, j - 1, GREEN) * -2) + (src.getPixel(i, j + 2, GREEN) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, GREEN) * -1) + (src.getPixel(i + 1, j + 1, GREEN))); // gx bottom row

				int gyGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j, GREEN) * -2) + (src.getPixel(i - 1, j + 1, GREEN) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, GREEN) * 1) + (src.getPixel(i + 1, j, GREEN) * 2) + (src.getPixel(i + 1, j + 1, GREEN))); // gy bottom row

				int GGREEN = sqrt((gxGREEN*gxGREEN) + (gyGREEN*gyGREEN));

				int I = ((GRED + GBLUE + GGREEN) / 3);


				if (I < t2)
				{
					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
				}
				else
				{
					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
				}
			}
			else if ((nROI == 3) && ((i > roiy3 - roisy3) && (i < roiy3 + roisy3)) && ((j > roix3 - roisx3) && (j < roix3 + roisx3)))
			{
				int gxRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j + 1, RED)) //gx top row
					+ (src.getPixel(i, j - 1, RED) * -2) + (src.getPixel(i, j + 2, RED) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, RED) * -1) + (src.getPixel(i + 1, j + 1, RED))); // gx bottom row

				int gyRED = ((src.getPixel(i - 1, j - 1, RED) * -1) + (src.getPixel(i - 1, j, RED) * -2) + (src.getPixel(i - 1, j + 1, RED) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, RED) * 1) + (src.getPixel(i + 1, j, RED) * 2) + (src.getPixel(i + 1, j + 1, RED))); // gy bottom row

				int GRED = sqrt((gxRED*gxRED) + (gyRED*gyRED));

				int gxBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j + 1, BLUE)) //gx top row
					+ (src.getPixel(i, j - 1, BLUE) * -2) + (src.getPixel(i, j + 2, BLUE) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, BLUE) * -1) + (src.getPixel(i + 1, j + 1, BLUE))); // gx bottom row

				int gyBLUE = ((src.getPixel(i - 1, j - 1, BLUE) * -1) + (src.getPixel(i - 1, j, BLUE) * -2) + (src.getPixel(i - 1, j + 1, BLUE) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, BLUE) * 1) + (src.getPixel(i + 1, j, BLUE) * 2) + (src.getPixel(i + 1, j + 1, BLUE))); // gy bottom row

				int GBLUE = sqrt((gxBLUE*gxBLUE) + (gyBLUE*gyBLUE));

				int gxGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j + 1, GREEN)) //gx top row
					+ (src.getPixel(i, j - 1, GREEN) * -2) + (src.getPixel(i, j + 2, GREEN) * 2) // gx middle row
					+ (src.getPixel(i + 1, j - 1, GREEN) * -1) + (src.getPixel(i + 1, j + 1, GREEN))); // gx bottom row

				int gyGREEN = ((src.getPixel(i - 1, j - 1, GREEN) * -1) + (src.getPixel(i - 1, j, GREEN) * -2) + (src.getPixel(i - 1, j + 1, GREEN) * -1) //gy top row
					+ (src.getPixel(i + 1, j - 1, GREEN) * 1) + (src.getPixel(i + 1, j, GREEN) * 2) + (src.getPixel(i + 1, j + 1, GREEN))); // gy bottom row

				int GGREEN = sqrt((gxGREEN*gxGREEN) + (gyGREEN*gyGREEN));

				int I = ((GRED + GBLUE + GGREEN) / 3);


				if (I < t3)
				{
					tgt.setPixel(i, j, RED, MINRGB);
					tgt.setPixel(i, j, GREEN, MINRGB);
					tgt.setPixel(i, j, BLUE, MINRGB);
				}
				else
				{
					tgt.setPixel(i, j, RED, MAXRGB);
					tgt.setPixel(i, j, GREEN, MAXRGB);
					tgt.setPixel(i, j, BLUE, MAXRGB);
				}
			}
			else
			{
				tgt.setPixel(i, j, RED, src.getPixel(i, j, RED));
				tgt.setPixel(i, j, GREEN, src.getPixel(i, j, GREEN));
				tgt.setPixel(i, j, BLUE, src.getPixel(i, j, BLUE));
			}
		}
	}
}