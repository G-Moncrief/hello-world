#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
	//prompts user for number of shares and price until an invalid input is entered

	vector <double> prices, numshares;
	double shares, price, total(0);

	cout << "Enter the number of shares and price per share. Enter Q to quit: ";
	cin >> shares >> price;

	while (!cin.fail())
	{
		numshares.push_back(shares);
		prices.push_back(price);
		total += shares * price;
		cout << "Enter the number of shares and price per share. Enter Q to quit: ";
		cin >> shares >> price;
		if (shares <= 0 || price <= 0)
			break;
	}

	cout << fixed;
	for (int i = 0; i < numshares.size(); i++)
		cout << setw(5) << setprecision(1) << numshares[i] << " shares at $"
		<< setw(6) << setprecision(2) << prices[i] << " = $"
		<< setw(8) << numshares[i] * prices[i] << endl;

	cout << "=========\n"
		<< "     Total: $";
	cout << setprecision(2) << total << endl;
	system("PAUSE");

	return 0; 
}
