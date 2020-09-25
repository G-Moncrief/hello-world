#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
  //Prompt user for # shares & price until invalid input
  vector<double> prices, numshares;

  double shares, price, total(0);

  cout << "Enter # of shares and price per share:  ";
  cin >> shares >> price;

  while (!cin.fail())
  {
    numshares.push_back(shares);
    prices.push_back(price);
    total += shares * price;
    cout << "Enter # of shares and price per share:  ";
    cin >> shares >> price;
    if (shares <= 0 || price <= 0)
      break;
  }

  cout << fixed;
  for (int i = 0; i < numshares.size(); i++)
    cout << setw(5) << setprecision(1) << numshares[i] << " shares at $"
         << setw(6) << setprecision(2) << prices[i] << " = $" 
         << setw(8) << numshares[i] * prices[i] << endl;

  //Print out total cost (to 2 decimal places)
  cout << "===================================\n"
       << "                   Total: $";
  cout << setprecision(2) << total << endl;

  return 0;
}
