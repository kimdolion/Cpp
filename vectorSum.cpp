// Kimberly Wilkes
// CIT 237
// February 6, 2020

// sum with vectors
#include <iostream>
#include <vector>
using namespace std;

int sumVectors(vector<int>);

int main() {
	int values;
	vector<int> userValues;
	int userTotal;
	cout << "How many numbers do you want to add? ";
	cin >> values;
	cout << "Okay, you want to add " << values << endl;
	for (int count = 0; count < values; count++) {
		int tempValue;
		cout << "Enter a value: ";
		cin >> tempValue;
		userValues.push_back(tempValue);
	}

	sumVectors(userValues);
	userTotal = sumVectors(userValues);
	cout << "Your total is " << userTotal << endl;
	system("pause");
	return 0;
}
int sumVectors(vector<int> vect)
{
	int total = 0;
	if (vect.empty()) {
		cout << "There are no numbers.\n";
	}
	else {
		for (int j = 0; j < vect.size(); j++) {
			total += vect[j];
		}
		return total;
	}
}
//int sum = 0;
//vector<int> numbers{ 6, 3, 4 };
//cout << "We are going to add up the vector { 6, 3, 4}.\n";
//for (int i = 0; i < numbers.size(); i++) {
//	sum += numbers[i];
//}
//cout << "The sum of those numbers using a for loop is " << sum << endl;
