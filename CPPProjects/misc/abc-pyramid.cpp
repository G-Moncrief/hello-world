/*

	Prints the alphabet in a pyramid

 */



#include <iostream>
#include <string>
using namespace std;

int main()
{
	string abc = "abcdefghijklmnopqrstuvwxyz";
	string blank = "";
	
	for (i = 1; i <= abc.length(); i++)
	{
		blank = blank + abc.substr(0, i) + '\n';
	}
	
	cout << blank;
	
	return 0;
	
}
