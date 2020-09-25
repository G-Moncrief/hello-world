/*
    
	PROBLEM: replace all spaces in a string with '%20'
	
	CLARIFY:  check the character set
	
	HINT: a common approach to string manipulation problems is to start at
	the end and work backwards, allowing us to change characters without 
	worrying about overwriting anything.
	
	SOLUTION:  use two scans. First one to count the number of spaces and 
	the second to actually edit the string.
	
*/

#include<bits/stdc++.h>

void urlify (std::string &str)
{
	int spacecount = 0, newlen = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			spacecount ++;
	}
	
	newlen = str.length()+ 1 + (spacecount * 2);
	char urlstr[newlen];
	for (int i = (str.length()-1); i >= 0; i--){
		if (str[i] == ' '){
			urlstr[newlen - 1] = '0';
			urlstr[newlen - 2] = '2';
			urlstr[newlen - 3] = '%';
			newlen = newlen - 3;
		} else {
			urlstr[newlen - 1] = str[i];
			newlen = newlen - 1;
		}
	}
			
	std::cout << urlstr ;
}

int main()
{
	std::string str = "Mr Test String";
	urlify(str);
	
	return 0;
}