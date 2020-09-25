#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

#include "link.h"
//=================================================default constructor
Link :: Link ()
{
}

//====================================================== constructor
Link :: Link (const string disp, const string addr)
{
	linkDisp = disp;
	linkAddr = addr;
}

//==================================returns the link text returned to the user
string Link :: print()
{
	return linkDisp;
}

//=========================returns the link addr returned to choose next section
string Link :: go()
{
	return linkAddr;
}
