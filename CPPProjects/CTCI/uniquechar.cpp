/*
    	PROBLEM:  determine if a string has all unique characters
	
	CLARIFY:  ask if ASCII or Unicode
	
	HINT:     if the string exceeds the unique character number of the 
		  aphabet then immediately return false 
	
	SOLUTION:  array of bool values where index i indicates if char i in alpha
		   if i returns a true (second time) then the function returns false
			   
		   naive solutions: compare every char to every other char O(n2)
			   
		   this would have a time complexity of O(n), or arguably O(1) as loop will never iterate
		   through more than 128 chars. The space complexity is O(1). Without a fixed char set
		   the complexities would be O(c)
	
*/

#include<bits/stdc++.h>

bool isUniqueChars(std::string &str) {
	if (str.length() > 128) return false; //if str exceeds the chars in alphabet, false

	bool char_set[128] = {false}; //bool array to store values for char index
		for (int i = 0; i < str.length(); i++) {
			int val = str[i]; //set val to the character in the str 
			if (char_set[val]==true) //if value has a true it has appeared in string, ret false
				return false;
			char_set[val] = true; //else store a true val to indicate char has been seen
		}
	return true; //if loop doesn't return false then the str contains all unique chars
}

int main()
{
	std::string str = "ENTER TEST TEXT HERE";
	if (isUniqueChars(str))
		std::cout << "\nCharacters Are Unique\n";
	std::cout << "\nCharacters Are Not Unique\n";
	return 0;
}
