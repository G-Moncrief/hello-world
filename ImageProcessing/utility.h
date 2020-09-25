#ifndef UTILITY_H
#define UTILITY_H

#include "../image/image.h"
#include <sstream>
#include <math.h>

class utility
{
	public:
		utility();
		virtual ~utility();
		static std::string intToString(int number);
		static int checkValue(int value);
		static void addGrey(image &src, image &tgt, int value);
		static void binarize(image &src, image &tgt, int T1, int T2);
		static void scale(image &src, image &tgt, float ratio);
		static void utility::rgbmod(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int rmod, int gmod, int bmod, int roix2, int roiy2, int roisx2, int roisy2, int rmod2, int gmod2, int bmod2, int roix3, int roiy3, int roisx3, int roisy3, int rmod3, int gmod3, int bmod3);
		static void utility::rgbbin(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int rgb, int T1, int roix2, int roiy2, int roisx2, int roisy2, int rgb2, int T2, int roix3, int roiy3, int roisx3, int roisy3, int rgb3, int T3);
		static void utility::smooth2d(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int roix2, int roiy2, int roisx2, int roisy2, int roix3, int roiy3, int roisx3, int roisy3);
		static void utility::incsmooth1d(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int roix2, int roiy2, int roisx2, int roisy2, int roix3, int roiy3, int roisx3, int roisy3);
		static void utility::autothresh(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int limit1, int target1, int smooth1, int roix2, int roiy2, int roisx2, int roisy2, int limit2, int target2, int smooth2, int roix3, int roiy3, int roisx3, int roisy3, int limit3, int target3, int smooth3);
		static void utility::rgbautothresh(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int hsi, int roix2, int roiy2, int roisx2, int roisy2, int hsi2, int roix3, int roiy3, int roisx3, int roisy3, int hsi3);
		static void utility::sobelint(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int roix2, int roiy2, int roisx2, int roisy2, int roix3, int roiy3, int roisx3, int roisy3);
		static void utility::sobelbw(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int t1, int roix2, int roiy2, int roisx2, int roisy2, int t2, int roix3, int roiy3, int roisx3, int roisy3, int t3);
		static void utility::sobelang(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int t1, int roix2, int roiy2, int roisx2, int roisy2, int t2, int roix3, int roiy3, int roisx3, int roisy3, int t3);
		static void utility::sobelcolor(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int t1, int roix2, int roiy2, int roisx2, int roisy2, int t2, int roix3, int roiy3, int roisx3, int roisy3, int t3);
		static void utility::sobelhsi(image &src, image &tgt, int nROI, int roix, int roiy, int roisx, int roisy, int t1, int roix2, int roiy2, int roisx2, int roisy2, int t2, int roix3, int roiy3, int roisx3, int roisy3, int t3);
};

#endif

