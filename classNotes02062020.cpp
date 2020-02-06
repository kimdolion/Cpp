// Kimberly Wilkes
// CIT 237
// February 6, 2020

// Focused on vectors
#include <iostream>
#include <vector>
using namespace std;

void display(vector<int>);
int main() {
	// vector <datattype> vector variable(size);
	//							size = how many elements you want to store;
	// vector<int> number(5);
	// when we initialize arrays int number[5] = {  };
	// initialize vectors as vector<int> numbers {  };
	vector<int> number { 7, 8, 9, 0, 0 };
	cout << "Created a function to display values.\n";
	display(number);
	cout << "this is a for loop displaying a vector\'s values.\n";
	for (int i = 0; i < 5; i++) {
		// or use a range based for loop
		// for(int i : number)
		// or a reference variable
		// for (int i& :number)
		cout << number[i];
	}
	cout << endl << "This is a for loop using size to display vector values.\n";
	// when you don't know the size of the vector you can use .size()
	for (int i = 0; i < number.size(); i++) {
		cout << number[i] << endl;
	}
	// testing the push_back function
	cout << "This is testing the push back function to add 5 to the end of the vector.\n";
	number.push_back(5);
	for (int i = 0; i < number.size(); i++) {
		cout << number[i] << endl;
	}
	// testing clear function
	cout << "Testing the clear function.\n";
	number.clear();
	for (int i = 0; i < number.size(); i++) {
		cout << number[i] << endl;
	}
	
	void display(vector<int> num) {
		for (int i = 0; i < num.size(); i++)
			cout << num[i] << endl;
	}
	return 0;
}