#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

#include "cmdimp.h"
#include "interp.h"

unordered_map <string, bool> u;
bool condOverride = false;	 									//true when if command fails otherwise true

//=======implements commands

void cmdImp (const string inc)
{	
	string s;
	
	size_t chkif = inc.find("(if");                 bool a = (chkif != std::string::npos);
	size_t chkelif = inc.find("e-f");             bool b = (chkelif != std::string::npos);
	size_t chkelse = inc.find("(else");        bool c = (chkelse != std::string::npos);
	size_t chkset = inc.find("set");             bool d = (chkset != std::string::npos);
	size_t chkdisp = inc.find("display");     bool e = (chkdisp != std::string::npos);
	
	if (d == true && a==false && b == false && c == false && e == false)		//set only
		setBuilder(inc);
	
	if (e == true && a==false && b == false && c == false && d == false)	//disp only
		display(inc);
	
	//=============================================if statement exists
	if (a == true || (b == true && condOverride == true) ){
		string var;
		bool desiredVal;
		size_t findVar = inc.find("$");
		size_t findValue = inc.find("true");
		size_t oB = inc.find("[");
		for (int i = findVar+1 ; i < inc.length() ; i++)
		{
			if (inc[i] != ' ')
				var += inc[i];
			else
				break;
		}
		if (findValue > findVar && findValue < chkelif)
			desiredVal = true;
		else
			desiredVal = false;
		
		auto search = u.find(var);
		if (search->second == desiredVal){
			for ( int i = oB+1 ; i < inc.length() ; i++){
				if (inc[i] != ']')
					cout << inc[i];
				else
					break;
			}
						 
			condOverride = false;
		}
		else
			condOverride = true;
	}
	//=============================================else-if statement exists
	if (b == true && condOverride == true){
		string ss = inc.substr(chkelif, inc.length() - chkelif -1);
		cmdImp(ss);
	}
	//=============================================else statement exists
	if (c == true && condOverride ==true){
		s = inc.substr(chkelse, inc.length() - chkelse -1);
		size_t openB = s.find("[");
		while (s[openB+1] != ']'){
			cout << s[openB+1];
			openB++;
		}
	}
}

//==================================builds sets and stores in unordered map u
void setBuilder (const string inc)
{
	size_t found = inc.find("$");
	size_t status = inc.find("rue");									//is it true?
	string setbuild;
	bool setchk;
	
	for (int i = found+1 ; i < inc.length() ; i++)
		if (inc[i] != ' ')
			setbuild += inc[i];
		else
			break;
	
	if (status != std::string::npos)
		setchk = true;
	else
		setchk = false;
	
	auto search = u.find(setbuild);
	if (search != u.end())
		search->second = setchk;
	else
		u [setbuild] = setchk;
	
	//bucketCheck();
}

void display (const string inc)
{
	size_t strt = inc.find(";");
	string builder;
	for (int i = strt+1 ; i < inc.length() ; i++){
		if (inc[i]!=';')
			builder += inc[i];
		else
			break;
		}
	Interp temp(builder);
	temp.textBuilder();
}

//========================================testing only...what's in the buckets?
void bucketCheck ()															
{
  std::cout << "mymap's buckets contain:\n";
  for ( unsigned i = 0; i < u.bucket_count(); ++i) {
    std::cout << "bucket #" << i << " contains:";
    for ( auto local_it = u.begin(i); local_it!= u.end(i); ++local_it )
      std::cout << " " << local_it->first << ":" << local_it->second;
    std::cout << std::endl;
  }
  }