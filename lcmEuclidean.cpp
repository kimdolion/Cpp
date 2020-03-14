/*
Write a c++ program to find least common multiple (LCM) of two, three and four integer values.
The integer values are entered from the keyboard and the outputs are printed to the console.
The LCM of two, three and four integer values are computed using the Euclidean algorithm.
You have to use arrays to hold input values and use functions/methods to get data from the keyboard,
    display output to the console, calculate LCM using Euclidean algorithm.  
*/
#include <iostream>
#include <iomanip>

using namespace std;

// LCM(x,y)=(x*y)/GCD(x,y) 
/*
int greatestCommonDenom(int, int);
*/
void displayArray(int[], int);

int main() {
    int sizeOfArray, userValue;
    cout << "You can enter between 2 and 4 numbers into this LCM calculator.\n"
        << "Enter how many numbers you want to use for this LCM calculator: ";
    cin >> sizeOfArray;
    // a while loop for input validation if user inputs numbers outside the given range.
    // user will be directed to enter a number in the range until they comply.
    while (sizeOfArray < 2 || sizeOfArray > 4) {
        cout << "You must enter an integer between 2 and 4.\n";
        cin >> sizeOfArray;
    }
    // once user has complied with first set of directions
    // then the program will be ready to take in values between 2 and 100 for an array.
    if (sizeOfArray > 1 && sizeOfArray < 5) {
        int values[sizeOfArray]; // initialize array with the size given from the user.
        // prepare the array for the actual user values
        for (int i = 0; i < sizeOfArray; i++) {
            cout << "Now enter values between 2 and 100 for number " << i << ": ";
            cin >> userValue;
            // if the value is within the range then add it to the array.
            if (userValue > 1 && userValue < 101) {
                values[i] = userValue;
            }
            else {
                cout << "You must enter values between 2 and 100.\n";
                i-= 1;
            }
        }
        cout << endl;
        displayArray(values, sizeOfArray);
        
    }
    return 0;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "In the array at position " << i << ": " << arr[i] << endl;
    }
}
/*
int leastCommonMultiple() {
    // LCM(x,y)=(x*y)/GCD(x,y) 
    greatestCommonDenom();
}

int greatestCommonDenom(int a, int b) { // find the greatest common denominator between 2 numbers
    int remain;
    // find the remainder of two variables
    while ((a % b) > 0)  {
        remain = a % b;
        a = b;
        b = remain;
    }
  return b;
}
*/
