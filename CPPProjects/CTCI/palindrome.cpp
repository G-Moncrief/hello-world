/*
    PROBLEM: given a string check if it is a permutation of a palindrome
	
	CLARIFY:  palindrome not limited to just dictionary words
	
	ASSUMPTION: want case sensative and white space does matter
	
	HINT: almost all characters must be in even numbers. Middle char can
	have an odd count. Therefore string may only have one char with odd count.
	
	SOLUTION 1:  use a hash table to count times each character appears and make 
	sure that no more than one character has an odd count. Solution takes O(N)
	
*/
#include <string>
#include <iostream>
#include <vector>

//maps chars to a number...non-letter chars map to -1
int char_number (const char &c)
{
	int a = (int) 'a';
	int z = (int) 'z';
	int A = (int) 'A';
	int Z = (int) 'Z';
	int val = (int) c;
	if (a <= val && val <= z)
		return val - 'a';
	else if (A <= val && val <= Z)
		return val - 'A';
	return -1;
}

std::vector <int> char_freq_table(std::string phrase){
	std::vector <int> table(char_number('z') - char_number('a') + 1, 0); //vec of size x all values 0
	for (char &c : phrase) {
		int x = char_number(c);
		if (x != -1)
			table[x]++;
	}
	
	return table;
}

bool check_odds (std::vector <int> &table)
{
	bool odd = false;
	for (auto count : table)
	{
		if (count % 2 == 1){
			if (odd)
				return false;
			odd = true;
		}
	}
	return true;
}

bool is_perm_of_palindrome (const std::string &phrase)
{
	std::vector <int> table = char_freq_table(phrase);
	return check_odds(table);
}
	

int main()
{
	std::string test = "abc";
	if (is_perm_of_palindrome(test))
		std::cout << "\nString is a Palindrome\n";
	else
		std::cout << "\nString is not a Palindrome\n";
	return 0;
}