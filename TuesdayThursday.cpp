//Kimberly Wilkes
//July 11, 2019
//Programming Warm-Up - Tuesday or Thursday
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char day;
	cout << "Is it Tuesday?\n Y for yes, N for no.\n";
	cin >> day;
	if (day == 'Y' || day == 'y' || day == 'N' || day == 'n')
	{
		if (day == 'Y' || day == 'y')
		{
			cout << "You have class today.\n";
		}
		else
		{
			cout << "Is it Thursday?\n Y for yes, N for no.\n";
			cin >> day;

			if (day == 'y' || day == 'Y')
			{
				cout << "You have class today.\n";
			}
			else
			{
				cout << "No class today!\n";
			}
		}
	}
	else
	{
		cout << "Invalid Entry. You must enter Y for yes or N for no.\n";
	}
	system("pause");
	return 0;
}