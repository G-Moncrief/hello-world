#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "link.h"
#include "delve.h"

string find_start (const string str);

bool end_of_story = false;


main ()
{
	ifstream pFile ("if.html");
	
	if (pFile.is_open())
	{
		cout << "\n\nOPENING FILE....\n" << endl;
		stringstream buf;
		buf << pFile.rdbuf();
		string story = buf.str();
		string pass_name;
		
		//finds first passage's passagedata tag
		size_t start_check = story.find ("<tw-passagedata"); 
		if (start_check != std::string::npos)
		{
			string snippet;
			for (int i = start_check ; i < story.length() ; i++)
			{
				if (story[i] != '\n')
					snippet += story[i];
				else
				{
					pass_name = find_start (snippet);
					break;
				}
			}
		}
		else 
		{
			cout << "Could not find any passagedata in file" << endl;
			pass_name = "@#$GAMEOVER";
		}
		
		//loop that runs story
		while (end_of_story != true)
		{
			pass_name = Delve (story, pass_name);
			if (pass_name == "@#$GAMEOVER")
			{
				end_of_story = true;
				cout << endl << "\t\t THE END" <<endl;
			}
		}
	}
	
	else
		cout << "cannot find file";
	
	return 0;
}

string find_start (const string str)
{
	size_t found = str.find("name="); //finds the name tag in the first passage's passagedata
	string s;
	if (found != std::string::npos)
	{
		for (int i = found+6; i < str.length() ; i++) //builds str to return as the first pass_name until it reaches closing "
		{
			if (str[i] != '\"')
				s += str[i];
			else
				return s;
		}
	}
	else
		cout << "Cannot find name=\"xxx\" tag in first passage's passagedata" << endl;
	
	return "@#$GAMEOVER";
}

