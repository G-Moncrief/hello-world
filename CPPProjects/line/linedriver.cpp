#include <iostream>
#include <string>
using namespace std;

#include "line.h"

int main()
{
	double w [6]= {5,2,8,4.8,3.25,3};
	double x [6] = {7,3,4,3.5,4.75,4};
	double y [6] = {5,-0.5,8,0,5.5,4};
	double z [6] = {7,7,3,3.5,2.75,3};

	for (int i =0; i < 6; i++){
		Line L (w[i], x[i]);
		Line K (y[i], z[i]);
		cout << "\n===TEST CASE " << i+1 << "===\n" << endl;
		cout << "Line 1: " << L.getSlope() << "x + " << L.getIntercept() << endl;
		cout << "Line 2: " << K.getSlope() << "x + " << K.getIntercept() << endl;
		L.intersect(K);

	}
}