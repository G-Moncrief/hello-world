#include <stack>
#include <cassert>
#include <string>
#include <iostream>
#include "bracketMatcher.h"

int main ()
{
	string input;
	bool end = false;
	
	while (end == false){
		std::cout << "\nEnter a string to test: ";
		getline(cin, input);
		
		balanced (input);
	}
}