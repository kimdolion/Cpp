//Kimberly Wilkes
//July 25, 2019
//Geometry Calculator
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int choice;
	do
	{
		cout << "Geometry Calculator\n";
		cout << "\t 1.  Calculate the Area of a Circle\n";
		cout << "\t 2.  Calculate the Area of a Rectangle\n";
		cout << "\t 3.  Calculate the Area of a Triangle\n";
		cout << "\t 4.  Quit\n";
		cout << "\nEnter your choice (1-4)\n";
		cout << "--------------------------------------------\n";
		cin >> choice;

		while (choice < 1 || choice > 4)
		{
			cout << "You must enter 1, 2, 3, or 4 to begin.\n";
			cin >> choice;
		}
		if (choice != 4)
		{
			double area = 1, base = 1, height = 1, length = 1, width = 1, radius = 1, pi = 3.14159;
			switch (choice)
			{
			case 1:
				cout << "To calculate the area of a CIRCLE, please enter the radius of the circle.\n";
				if (radius > 0)
				{
					cin >> radius;
					area = pi * pow(radius, 2);
					cout << "The area of your circle is " << setprecision(4) << fixed << area << endl << endl;
				}
				else
				{
					cout << "Your radius must be greater than 0.\n";
				}
				break;

			case 2:
				cout << "To calculate the area of a RECTANGLE, please enter the length and width.\n";
				cin >> length >> width;
				if (length > 0 && width > 0)
				{
					area = length * width;
					cout << "The area of your rectangle is " << setprecision(4) << fixed << area << endl << endl;
				}
				else
				{
					cout << "Your length AND width must be greater than 0.\n";
				}
				break;

			case 3:
				cout << "To calculate the area of a CIRCLE, please enter the base and height of the triangle.\n";
				cin >> base >> height;
				if (base > 0 && height > 0)
				{
					area = base * height * .5;
					cout << "The area of your circle is " << setprecision(4) << fixed << area << endl << endl;
				}
				else
				{
					cout << "Your base AND height must be greater than 0.\n";
				}
				break;
			}
		}
		else
		{
			cout << "Goodbye!\n";
		}
	} while (choice != 4);

	system("pause");
	return 0;
}
