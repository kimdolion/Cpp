// Write two overloaded functions that return the average of an array. 
// Write a test program that prompts the user to enter 15 integers, invokes the first function, then displays the average value; 
// prompts the user to enter 15 double values, invokes the second function, then displays the average value.
#include <iostream>
using namespace std;

int arrayAverage(int, int);
double arrayAverage(double, double);

int main() {
    int sumInts = 0, intSize = 15, averageIntResult;
    int intArray[15];
    double sumDoubles = 0, doubleSize = 15, averageDoubleResult;
    double doubleArray[15];
    cout << "Overloaded array averaging functions using int and double.\n";
    cout << "Enter 15 integers: ";
    for (int i = 0; i < 15; i++) {
        cin >> intArray[i];
        sumInts += intArray[i];
    }
    averageIntResult = arrayAverage(sumInts, intSize);
    cout << "The int average is: " << averageIntResult << endl;
    
    cout << "Enter 15 doubles: ";
    for (int j = 0; j < 15; j++) {
        cin >> doubleArray[j];
        sumDoubles += doubleArray[j];
    }
    averageDoubleResult = arrayAverage(sumDoubles, doubleSize);
    cout <<  "The double average is: " << averageDoubleResult << endl;
    return 0;
}

int arrayAverage(int sum, int size) {
    int averageSumInts;
    return averageSumInts = sum / size;
}

double arrayAverage(double sum, double size) {
    double averageSumDoubles;
    return averageSumDoubles = sum / size;
}
