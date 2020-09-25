#include <stack>
#include <cassert>
#include <iostream>
#include "bracketMatcher.h"

string left_brackets("[({");
string right_brackets("])}");

bool is_left(char c)
{
  return left_brackets.find(c) != string::npos;
}

bool is_right(char c)
{
  return right_brackets.find(c) != string::npos;
}

bool matches(char L, char R)
{
  assert(is_left(L) && is_right(R));
  return left_brackets.find(L) ==  right_brackets.find(R);
}

bool balanced(string str)
{ 
	stack<char> S;
	for(int i = 0; i < str.length(); i++){
		//==========================If char is an opening bracket it gets added to the stack
		if (is_left(str[i]))
			S.push(str[i]);
		//=======================if char is a closing bracket funct checks for match on stack
		else if(is_right(str[i]) && !S.empty()){
			if(matches(S.top(), str[i])) //					if match exists the paired bracked pops off stack
				S.pop();
			else{ //									if match doesn't exist couts error msg and returns FALSE
				std::cout << "Bracket mismatch at index "<<i<<": "<<S.top()<<" and " <<str[i] << std::endl;
				return 0;
			}	
		}
		//========if char is closing bracket and stack empty couts error msg and returns FALSE
		else if(is_right(str[i]) && S.empty()){
			std::cout << "\nUnmatched bracket at index " <<i <<": "<<str[i]<< std::endl;
			return 0;
		}
	}
	//=============if stack is not empty after str is parsed couts error msg and returns FALSE
	if (!S.empty()){
		std::cout<<"\nUnmatched bracket at index "<<str.length() <<": " << S.top() <<std::endl;
		return 0;
	}
	//==========if stack is empty after string has been parsed couts success and returns TRUE
	if (S.empty()){
		std::cout<<"\nThe brackets in your string are properly matched" << std::endl;
		return 1;
	}
}
    
