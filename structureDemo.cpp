// Structure
#include <iostream>
using namespace std;

// structures are used for different data types;
// better than using an array which can only store things of the same type
// declare the structure outside of main

struct Student {
	string studentName;
	int age;
	double gpa;
// unlike the functions, the structure needs a semi colon at end of it
};

int main() {

	Student s1;
	// access the structure using dot notation
	cout << "Enter the student's name: ";
	cin >> s1.studentName;
	cout << "Student name is: " << s1.studentName << endl << endl;
	// but creating each student with its own declared variable would be a pain
	// so use an array and a loop.
	int numberOfStudents;
	Student studentArray[30];
	cout << "Now we are creating an array of students.\n";
	cout << "Enter the number of students you are creating: ";
	cin >> numberOfStudents;
	for (int i = 0; i < numberOfStudents; i++) {
		cout << "Enter the student's name: ";
		cin >> studentArray[i].studentName;
		cout << "Enter the student's age: ";
		cin >> studentArray[i].age;
		cout << "Enter the student's gpa: ";
		cin >> studentArray[i].gpa;
		cout << endl;
	}
	cout << endl;
	cout << "Now displaying the array of students.\n";
	for (int j = 0; j < numberOfStudents; j++) {
		cout << "Student " << j + 1 << ": " << studentArray[j].studentName;
		cout << "\t\tAge: " << studentArray[j].age;
		cout << "\t\tGPA: " << studentArray[j].gpa << endl;
	}
	return 0;
}