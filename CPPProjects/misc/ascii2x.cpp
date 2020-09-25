/*	Garrett Moncrief
*
*	This program takes two files named left.txt and right.txt and align them side by
*	by side. Uses token to determine the height and width from the input txt files
*
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	ifstream front("left.txt");
	ifstream back("right.txt");
	ofstream out("output.txt");
	if (front.is_open() && back.is_open())
	{
		string leftH, leftW, rightH, rightW;
		string sLine1, sLine2;

		//tokenizes the height/width from input txt
		front >> leftH >> leftW;
		back >> rightH >> rightW;

		//converts left/right height/width strings to int
		int LH = std::stoi(leftH);
		int LW = std::stoi(leftW);
		int RH = std::stoi(rightH);

		//keeps the original height of the left image so if right image is larger
		//it will print blank spaces (this is handled by the int k variable)
		int ogLH = LH;
		int count = 0;

		//if the right image is larger than the left image increase
		//left image height so formatting is preserved
		while (RH > LH)
			LH++;

		for (int i = 0; i < LH; i++)
		{
			getline(front, sLine1);
			if (count < ogLH)
			{
				out << sLine1;
				//if line width is shorter than max line width enters spaces to preserve formatting 
				if (sLine1.length() < LW)
					for (int j = sLine1.length(); j < LW; j++)
						out << " ";
			}
			else
			{
				//as mentioned above this prints spaces for the width of the image
				for (int k = 0; k < LW; k++)
					out << " ";
			}
			out << " ";
			getline(back, sLine2);
			out << sLine2;
			out << "\n";
			count++;
		}

	}
	else
		cout << "Unable to open a neccessary file\n\n";

	return 0;
}
