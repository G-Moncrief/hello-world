#include "utility.h"

#define MAXRGB 255
#define MINRGB 0

using namespace cv;

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
void utility::binarize(image &src, image &tgt, int threshold)
{
	tgt.resize(src.getNumberOfRows(), src.getNumberOfColumns());
	for (int i=0; i<src.getNumberOfRows(); i++)
	{
		for (int j=0; j<src.getNumberOfColumns(); j++)
		{
			if (src.getPixel(i,j) < threshold)
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
			int i2 = (int)floor((float)i/ratio);
			int j2 = (int)floor((float)j/ratio);
			if (ratio == 2) {
				tgt.setPixel(i,j,checkValue(src.getPixel(i2,j2)));
			}

			if (ratio == 0.5) {
				int value = src.getPixel(i2,j2) + src.getPixel(i2,j2+1) + src.getPixel(i2+1,j2) + src.getPixel(i2+1,j2+1);
				tgt.setPixel(i,j,checkValue(value/4));
			}
		}
	}
}

/*-----------------------------------------------------------------------**/
void utility::cv_gray(Mat &src, Mat &tgt)
{
	cvtColor(src, tgt, COLOR_BGR2GRAY);
}

/*-----------------------------------------------------------------------**/
void utility::cv_avgblur(Mat &src, Mat &tgt, int WindowSize)
{
	blur(src,tgt,Size(WindowSize,WindowSize));
}

/*-----------------------------------------------------------------------**/
void utility::cv_norm (cv::Mat &src, cv::Mat &tgt, int alpha, int beta)
{
  normalize(src, tgt, alpha, beta, NORM_MINMAX);
}

/*-----------------------------------------------------------------------**/
void utility::cv_qr(Mat &src, Mat &tgt)
{
}

/*-----------------------------------------------------------------------**/
void utility::cv_eq (Mat &src, Mat &tgt)
{
  cvtColor( src, src, COLOR_BGR2GRAY );
  equalizeHist( src, tgt );
}
/*-----------------------------------------------------------------------**/
void utility::cv_roi (Mat &src, Mat &tgt)
{
  cvtColor( src, src, COLOR_BGR2GRAY );
  Mat roi = src( Rect (50,50,50,50));
  Mat roi2 = src (Rect (200, 150, 150, 150));
  Mat roi3 = src (Rect (100, 400, 100, 100));
  equalizeHist( roi, roi );
  equalizeHist( roi2, roi2 );
  equalizeHist( roi3, roi3 );
  tgt = src;
}

/*-----------------------------------------------------------------------**/
void utility::cv_sobel (cv::Mat &src, cv::Mat &tgt)
{
//note: implementation taken partially from https://docs.opencv.org/2.4.13.7/doc/tutorials/imgproc/imgtrans/sobel_derivatives/sobel_derivatives.html
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;
  
  cvtColor( src, src, COLOR_BGR2GRAY );
  //x sobel
  Sobel(src, tgt, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
  //y sobel
  Sobel(tgt, tgt, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
}
/*-----------------------------------------------------------------------**/

void utility::cv_canny (cv::Mat &src, cv::Mat &tgt)
{
  cvtColor( src, tgt, COLOR_BGR2GRAY );
  Canny(src, tgt, 50, 200);
}

/*-----------------------------------------------------------------------**/

void utility::cv_diff (cv::Mat &src, cv::Mat &tgt)
{
  cvtColor( src, src, COLOR_BGR2GRAY );
  Mat src2 = src;
  
  equalizeHist( src, src );
  Canny(src, src, 0, 255);
  Canny(src2, src2, 0, 255);
  subtract (src, src2, tgt);
}