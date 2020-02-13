// Kimberly Wilkes
// Write a program that reads the integers between 1 and 100 and counts the occurrences of each.
// Assume that input ends with - 1. 
// Numbers are displeyed in decreasing order when it is displayed the occurrence of each number. (2 points)

#include <iostream>
using namespace std;

int main() {
    int userInput, sizeOfCollection, endProgramInput = -1, n = 0;
    int collection[101] = { 0 };
    cout << "Enter integers that are between 1 and 100";
    cout << "and this will tell you how many times you entered that number.\n";
    cout << "Enter -1 when you are finished entering numbers.\n";
    while ((cin >> userInput) && userInput != endProgramInput) {
        if (userInput > 0 && userInput < 101) {
            collection[userInput + 1] += 1;
            n+= 1;
        } else {
            cout << "Your number must be between 1 and 100.\n";
        }
    }
    for (int i = 0; i < n; i++) {
        if (collection[i] != 0) {
            cout << i - 1 << " occurred " << collection[i] << " times.\n";
        }
    }
	return 0;
}