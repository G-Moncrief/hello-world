#ifndef __INTERP_H
#define __INTERP_H

string Delve (const string bulk, const string title);
string linkSelect();

class Interp{
	private:
		string passage;							//passage text
		
	public:
		Interp();
		Interp(const string pass);
		void textBuilder();
		void linkBuilder(const string passage);
		void cmdBuilder();
		
		friend string Delve (const string bulk, const string title);
};


#endif
