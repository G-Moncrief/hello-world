#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

#include "interp.h"
#include "link.h"

string FindStart (const string str);
	
main ()
{
	ifstream pFile ("if.html");
	if (pFile.is_open()){
//====================================================opens file and converts to string
		cout <<"\n\n\tOPENING FILE\n" << endl;
		stringstream buf;
		buf << pFile.rdbuf();
		string s = buf.str();
		
		string name; 																//passes the name of the passage to be read
		size_t pass1 = s.find("<tw-passagedata");				//finds the first passagedata tag
		
//==================================================find first passage's passagedata tag
		if (pass1 != std::string::npos){
			name = FindStart (s.substr(pass1, 256));
		}		
		else{
			cout << "Could not find passagedata tag in file" << endl;
			return -1;
		}
		
//============================================================loop that runs the story
		while (name != "@#$GaMeOVR"){
			name = Delve(s, name);
			if (name == "@#$GaMeOVR")
				cout << endl << "\t\tTHE END" << endl;
		}
	}
//=================================================exits program when if.html not found
	else
		cout << "Cannot read if.html" << endl;
	return 0;
}

//=========================================find the name="xxx" tag in the passagedata tag
string FindStart (const string str)
{
	size_t found = str.find("name=");									//finds the name tag
	string ret;																		//builds string to return
	
	if (found != std::string::npos){
		for (int i = found+6 ; i < str.length() ; i++){
			if (str[i] != '\"')
				ret += str[i];
			else
				return ret;
		}
	}
	else{
		cout << "Cannot find name=\"xxx\" tag in first passage's passagedata" << endl;
		return "@#$GaMeOVR";
	}
}

