//Kimberly Wilkes
//July 25, 2019
//Monthly Sales Tax
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string month;
	int year;
	double productSales, totalIncome, stateTax, countyTax, totalTax;
	cout << "Welcome to the Monthly Sales Tax Calculator!\n";
	cout << "Please enter the month.\n";
	cin >> month;
	cout << "Please enter the year.\n";
	cin >> year; 
	cout << "Please enter the total amount collected at the cash register.\n";
	cin >> totalIncome;
	productSales = totalIncome / 1.06;
	countyTax = productSales * 0.02;
	stateTax = productSales * 0.04;
	totalTax = countyTax + stateTax;
	cout <<endl << "Month: " << month << endl;
	cout << "-------------------------------------\n";
	cout << setprecision(2) << fixed << showpoint;
	cout << left << "Total Collected:  " << setw(5) << right << "$" << totalIncome << endl;
	cout << left << "Sales:            " << setw(5) << right << "$"  << productSales << endl;
	cout << left << "County Sales Tax: " << setw(5) << right << "$" <<  countyTax << endl;
	cout << left << "State Sales Tax:  " << setw(5) << right << "$" <<  stateTax << endl;
	cout << left << "Total Sales Tax:  " << setw(5) << right << "$"  << totalTax << endl;
	system("pause");
	return 0;
}