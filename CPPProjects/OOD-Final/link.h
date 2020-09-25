#ifndef __LINK_H
#define __LINK_H

class Link{
	private:
		string linkDisp;
		string linkAddr;
	public:
		Link ();
		Link(const string disp, const string addr);
		string print();
		string go();
};

#endif