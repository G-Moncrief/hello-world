#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

#include "interp.h"
#include "link.h"
#include "cmdimp.h"

void dispLinks ();
void cmdImp (const string inc);
string findPassage(const string bulk, const string pass);
	
vector<Link> linkList;											//creates vector of possible passage links


//===================Delve does the heavy lifting by calling functs to build links, disp, cmds, etc
string Delve (const string bulk, const string title)
{
	linkList.clear();												//clears any old links from linkList
	
	Interp page(findPassage (bulk, title)) ;
	page.textBuilder();
	//page.cmdBuilder();
	dispLinks();
	return linkSelect();
}

//============================================================default constructor
Interp :: Interp ()
{
}

//===========================================================standard constructor
Interp :: Interp (const string pass)
{
	passage = pass;
}

//=============================finds the specific passage out of the full page of HTML code
string findPassage (const string bulk, const string title)
{
	size_t found = bulk.find("\"" +title +"\"");		//find the pos of the segment in HTML file
	string passage;												//builds a passage from start tag to end tag
	int i = found;
	
	while (bulk[i] != '<'){
		passage += bulk[i];
		i++;
	}
	return passage;
}

//========================================================builds the text to display
void Interp :: textBuilder()
{
	size_t found = passage.find('>');
	for (int i = found+1; i < passage.length() ; ){
		if (passage[i] == '[' && passage[i+1] == '['){				//indicates a link
			i+= 2;																	//skips over brackets
			string build;														//for building string to send to Link
			while(passage[i] != ']'){ 									//build string until reach closing bracket
				build += passage[i];
				i++;
			}
			i+=2;
			Interp :: linkBuilder(build);
		}
		else if (passage[i] == '(' && (passage[i+3] == ':' ||passage[i+4] == ':' ||passage[i+5] == ':' ||passage[i+8] == ':')){
			string build;
			for ( ; ; i++){
				if (passage[i] != '\n')
					build += passage[i];
				else{
					cmdImp(build);
					break;
				}
			}
		}
		else{
			cout << passage[i];
			i++;
		}
	}
}

//===================================================finds links for the linkList vector
void Interp :: linkBuilder(const string passage)
{
	size_t found;													//for checking if a gt link	
	found = passage.find("&gt");
	if (found != std::string::npos){							//this is a gt link
		string gt_disp;
		string gt_go;
		for (int j = 0; j < found -1 ; j++)
			gt_disp += passage[j];
		for (int k = found+4; k < passage.length(); k++)
			gt_go += passage[k];
		linkList.push_back(Link(gt_disp,gt_go));
	}
	else{																	//this is a standard link
		linkList.push_back(Link(passage, passage));
	}
}


//================================================displays a list of the possible links
void dispLinks ()
{
	for (int i = 0; i < linkList.size() ; i++){
		cout << "\t" << i+1 << "\t" << linkList[i].print() << endl;
	}
}

//================================================get player selection for next action
string linkSelect ()
{
	int choose;
	string next;
	if (linkList.size() == 0)
		return "@#$GaMeOVR";
	else{
		cout << endl << "You choose to: ";
		cin >> choose;
		while (cin.fail() || choose > linkList.size() || choose <= 0){
			cout << "Please choose an above option: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> choose;
		}
		next = linkList[choose-1].go();
	}
	return next;
}













