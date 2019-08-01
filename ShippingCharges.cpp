//Kimberly Wilkes
//July 25, 2019
//Shipping Charges
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double weight, distance, shippingCost, twoKG = 1.1, sixKG = 2.2, tenKG = 3.7, twentyKG = 4.8;
	cout << "Enter the weight of the package.\n";
	cin >> weight;
	if (weight > 0 && weight <= 20)
	{
		cout << "Enter the distance it will be shipped.\n";
		cout << "You cannot ship your package a distance that is less than 10 miles or more than 3000 miles.\n";
		cin >> distance;
		if (distance >= 10 && distance <= 3000)
		{
			if (weight <= 2 && weight > 0)
			{
				shippingCost = twoKG * (distance / 500);
				cout << "Your shipping cost for a package weighing " << weight << " kg(s) going a distance of ";
				cout << distance << " miles will be $" << showpoint << setprecision(3) << shippingCost << endl;
			}
			else if (weight <= 6 && weight > 2)
			{
				shippingCost = sixKG * (distance / 500);
				cout << "Your shipping cost for a package weighing " << weight << " kgs going a distance of ";
				cout << distance << " miles will be $" << showpoint << setprecision(3) << shippingCost << endl;
			}
			else if (weight <= 10 && weight > 6)
			{
				shippingCost = tenKG * (distance / 500);
				cout << "Your shipping cost for a package weighing " << weight << " kgs going a distance of ";
				cout << distance << " miles will be $" << showpoint << setprecision(3) << shippingCost << endl;
			}
			else if (weight <= 20 && weight > 10)
			{
				shippingCost = twentyKG * (distance / 500);
				cout << "Your shipping cost for a package weighing " << weight << " kgs going a distance of ";
				cout << distance << " miles will be $" << showpoint << setprecision(3) << shippingCost << endl;
			}
		}
		else if (distance < 10)
		{
			cout << "You cannot ship your package less than 10 miles.\n";
		}
		else if (distance > 3000)
		{
			cout << "You cannot ship your package more than 3000 miles.\n";
		}
	}
	else if (weight < 0)
	{
		cout << "You cannot use negative numbers.\n";
	}
	else
	{
		cout << "Your package is too large to ship with us.\n";
	}
	system("pause");
	return 0;
}