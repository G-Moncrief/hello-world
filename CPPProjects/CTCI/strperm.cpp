/*
    	PROBLEM: given two str check to see if one is perm of other
	
	CLARIFY:  check if case sensative and white space matters
	
	ASSUMPTION: want case sensative and white space does matter
	
	HINT: strings of diff lens cannot be perm of each other 
	
	SOLUTION:  two solutions, 1) sort strings 2) check char counts
	
*/
#include<bits/stdc++.h>
#include<algorithm>

bool perm1 (std::string s, std::string t)
{
	if (s.length() != t.length()){ //if lengths don't match cannot be permutations
		return false;
	}
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());
	if (s.compare(t) == 0)
		return true;
	return false;
	//return (sort(s.begin(), s.end())).equals(sort(t.begin, t.end)); //check if sorted strings are same
}

bool perm2 (std::string s, std::string t)
{
	if (s.length() != t.length()){ //if lengths don't match cannot be permutations
		return false;
	}
	
	int counts = 0, countt = 0;
	for (int i = 0; i < s.length(); i++){
		counts += s[i];
		countt += t[i];
	}
	if (counts == countt)
		return true;
	else
		return false;
}

int main()
{
	std::string s = "ENTER TEST TEXT HERE";
	std::string t = "ENTER TEST TEXT HERE";
	if (perm1(s, t))
		std::cout << "\nStrings Are Permutations\n";
	else
		std::cout << "\nStrings Are Not Permutations\n";
	
	if (perm2(s, t))
		std::cout << "\nStrings Are Permutations\n";
	else
		std::cout << "\nStrings Are Not Permutations\n";
	
	return 0;
}
