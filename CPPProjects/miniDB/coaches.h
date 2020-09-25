#ifndef __COACHES_H
#define __COACHES_H

using namespace std;

class Coaches{
	private:
		string a;				//Coach_ID field
		int b;					//season field
		string c;			//first_name field
		string d;			//last_name field
		int e;				//season_win field
		int f;				//season_loss field
		int g;				//playoff_win field
		int h;				//playoff_loss filed
		string i;			//team field
	public:
		Coaches(string a, int b, string c, string d, int e, int f, int g, int h, string i): a(a),  b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {};
		string geta() {return a;};
		int getb() {return b;};
		string getc() {return c;};
		string getd() {return d;};
		int gete() {return e;};
		int getf() {return f;};
		int getg() {return g;};
		int geth() {return h;};
		string geti(){return i;};
		
};

#endif
