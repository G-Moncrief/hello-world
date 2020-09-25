#include <string>
using namespace std;

class RuntimeException { // generic run-time exception
 private:
  string errorMsg;
 public:
  RuntimeException(const string& err) { errorMsg = err; }
  string getMessage() const { return errorMsg; }
};

class EqualLines: public RuntimeException
{
 public:
	EqualLines(): RuntimeException("The lines are equal: infinite intersection") {}
};

class ParallelLines: public RuntimeException
{
 public:
	ParallelLines(): RuntimeException("The lines are parallel: no intersection") {}

};

// Recall that if you catch a EqualLines or ParalledLines exception as, say e, then you should print e.getMessage
class Line {
 public:
  Line(double slope, double y_intercept): a(slope), b(y_intercept) {};
  double intersect(const Line L) const ;
  double getSlope() const {return a;};
  double getIntercept() const {return b;};
    
 private:
  double a;
  double b;
};


