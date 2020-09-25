#include <iostream>
#include <limits>
using namespace std;

int main()
{
  int n;

  cout << "Enter an integer:  ";
  cin >> n;

  while (!cin)
  {
    cout << "INVALID INPUT\n";
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());

    cout << "Enter an integer:  ";
    cin >> n;
  }

  cout << "You entered " << n << endl;

  return 0;
}
