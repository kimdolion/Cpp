//Kimberly Wilkes
//July 25, 2019
//Energy Drinks
#include <iostream>
#include <iomanip>
using namespace std;

/* 
A soft drink company surveyed 16,500 of its customers and 
found that approximately 15 percent of them surveyed purchase one or more energy drinks per week.  
Of those customers who purchase energy drinks, approximately 58 percent of them prefer citrus-flavored energy drinks. 
Write a program that  displays, in sentences, the following:

The approximate number of customers in the survey who purchase one or more energy drinks per week.
The approximate number of customers in the survey who prefer citrus-flavored energy drinks.
*/


int main()
{
	int customers = 16500, oneOrMoreDrinks, citrusPreference;
	oneOrMoreDrinks = customers * .15;
	citrusPreference = oneOrMoreDrinks * .58;
	cout << "15% or approximately " << oneOrMoreDrinks << " customers purchase one or more energy drinks per week.\n";
	cout << "58% of that 15% or approximately " << citrusPreference << " of those customers prefer citrus flavored energy drinks.\n\n";
	system("pause");
	return 0;
}