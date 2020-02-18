// Structure
#include <iostream>
using namespace std;
// must use nested structure for students info
struct Grade {
	double grade1;
	double grade2;
	double grade3;
};
struct Student {
	int registrationNumber;
	string studentName;
	Grade gradesFor3Classes;
	double average;
};

int main() {
	Student studentArray[5];
	for (int i = 0; i < 5; i++) {
		double total = 0;
		studentArray[i].registrationNumber = i + 1;
		cout << "Enter the student's name: ";
		cin >> studentArray[i].studentName;
		cout << "Enter the student's 3 grades they want an average for.\n";
		cout << "Grade 1: ";
		cin >> studentArray[i].gradesFor3Classes.grade1;
		cout << "Grade 2: ";
		cin >> studentArray[i].gradesFor3Classes.grade2;
		cout << "Grade 3: ";
		cin >> studentArray[i].gradesFor3Classes.grade3;
		total += studentArray[i].gradesFor3Classes.grade1;
		total += studentArray[i].gradesFor3Classes.grade2;
		total += studentArray[i].gradesFor3Classes.grade3;
		studentArray[i].average = total / 3.0;
		cout << endl;
	}
	cout << endl;
	cout << "Now displaying the array of students.\n";
	for (int j = 0; j < 5; j++) {
		cout << "Registraton Number: " << studentArray[j].registrationNumber;
		cout << "\t\tStudent Name: " << studentArray[j].studentName;
		cout << "\t\tGPA: " << studentArray[j].average << endl;
	}
	return 0;
}