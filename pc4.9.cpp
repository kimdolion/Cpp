//Kimberly Wilkes
//July 11, 2019
// Programming Challenge - 4.9 Change for a Dollar Game
#include <iostream>
#include <string>
using namespace std;

int main()
{
	double coinValue, pennies, nickles, dimes, quarters;
	cout << "Enter the number of pennies.\n";
	cin >> pennies;
	if (pennies >= 0)
	{
		cout << "Enter the number of nickles.\n";
		cin >> nickles;
		if (nickles >= 0)
		{
			cout << "Enter the number of dimes.\n";
			cin >> dimes;
			if (dimes >= 0)
			{
				cout << "Enter the number of quarters.\n";
				cin >> quarters;
				if (quarters >= 0)
				{
					coinValue = pennies * 1 + nickles * 5 + dimes * 10 + quarters * 25;
					if (coinValue == 100)
					{
						cout << "Congrats you win!\n";
					}
					else if (coinValue > 100)
					{
						cout << "You made more than 1 dollar. Try again.\n";
					}
					else if (coinValue < 100)
					{
						cout << "You made less than 1 dollar. Try again.\n";
					}
				}
				else
				{
					cout << "You cannot use negative numbers.\n";
				}
			}
			else
			{
				cout << "You cannot use negative numbers.\n";
			}
		}
		else
		{
			cout << "You cannot use negative numbers.\n";
		}
	}
	else
	{
		cout << "You cannot use negative numbers.\n";
	}
	system("pause");
	return 0;
}