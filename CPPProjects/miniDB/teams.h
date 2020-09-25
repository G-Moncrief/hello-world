#ifndef __TEAMS_H
#define __TEAMS_H

using namespace std;

class Teams{
	private:
		string a;		//team_ID field
		string b;		//Location field
		string c;		//Name field
		string d;		//League field
	public:
		Teams(string a, string b, string c, string d): a(a), b(b), c(c), d(d) {};
		string geta() {return a;};
		string getb() {return b;};
		string getc() {return c;};
		string getd() {return d;};
};

#endif