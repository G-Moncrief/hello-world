// Programmer:
// Last modification date:

#include <iostream>
#include "line.h"

double Line::intersect(const Line L) const 
{
	try{
		if (getSlope() == L.getSlope() && getIntercept() == L.getIntercept())
			throw EqualLines();
		else if (getSlope() == L.getSlope())
			throw ParallelLines();
		else 
			return (L.getIntercept() - getIntercept()) / (getSlope() - L.getSlope());
	}
	catch (EqualLines& e){
		std::cout << e.getMessage() << std::endl;
	}
	catch (ParallelLines& e){
		std::cout << e.getMessage() << std::endl;
	}
}


