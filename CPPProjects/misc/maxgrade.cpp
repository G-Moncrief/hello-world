#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef struct
{
  string lname;
  string fname;
  int grade;
} grade_t;

int main()
{
  ifstream in("grades.txt");
  string line;
  int numstudents;
  istringstream iss;
  vector<grade_t> vec;

  in >> numstudents;
  getline(in, line);

  for (int i = 0; i < numstudents; i++)
  {
    getline(in, line);
    iss.str(line);
    grade_t x;

    iss >> x.fname >> x.lname >> x.grade;
    iss.clear();
    vec.push_back(x);
  }

  in.close();

  grade_t max = vec[0];
  for (int i = 1; i < numstudents; i++)
  {
    int grade = vec[i].grade;
    if (max.grade < grade)
    {
      max = vec[i];
    }
  }

  cout << "Max grade:  " << max.fname << ' ' << max.lname << " (" << max.grade << ")\n";

  return 0;
}
