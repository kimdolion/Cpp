#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream dataFile;
	cout << "Opening a file.\n";
	dataFile.open("demofile.txt", ios::app); // had started with ios::out, started testing append
	cout << "Demofile.txt is now open.\n";
	dataFile << "jones\n";
	dataFile << "jones\n";
	dataFile << "cat\n"; // to distinguish between the appended sets of jones
	dataFile << "jones\n";
	dataFile << "jones\n\n";
	dataFile.close();
	cout << "jones was written 4 times.\n";
	// now reading the first line from the file
	dataFile.open("demofile.txt", ios::in);
	string name;
	dataFile >> name;
	cout << name << endl; // returns the first thing that was put into the file
	dataFile.close();
	return 0;
}