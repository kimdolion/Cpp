// Write a program that randomly fills in 0s and 1s into a 5-by-5 matrix,prints the matrix,
// and finds which row and column with more 1s and display that row and column number.     
#include <iostream>
#include <iomanip> // lets me format the data into a 5 by 5 matrix
#include <cstdlib> // gives us the random generator function for 0s and 1s

using namespace std;

const int COLUMNS = 5;
const int ROWS = 5;
const int MIN_VALUE = 0;
const int MAX_VALUE = 1;

int main() {
    int countAllOnes = 0;
    int countOnesByRow = 0, mostOnes = 0, rowX = 0;
    unsigned seed = time(0);
    srand(seed);
    cout << "Random 0's and 1's in a 5 by 5 matrix.\n\n";
    
    int matrix[ROWS][COLUMNS];
    cout << "\t\tColumns\n";
    cout << "\t   1    2    3    4    5\n";
    cout << "-----------------------------------\n";
    for (int x = 0; x < ROWS; x++) {
        cout << "Row: " << x + 1 << "|";
        for (int y = 0; y < COLUMNS; y++) {
            // use rand to pick 0 or 1
            int randomLimit = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            // set the index to 0 or 1
            matrix[x][y] = randomLimit;
            // show the matrix by row of 5
            cout << setw(5) << matrix[x][y];
            // count how many 1s were created
            if (matrix[x][y] == 1) {
                countAllOnes += 1;
                countOnesByRow += 1;
            }
        }
         // if mostOnes at 0 is less than the count of Ones
        // set mostOnes to the current count
        if (mostOnes < countOnesByRow) {
            mostOnes = countOnesByRow;
            rowX = x;
        }
        // then reset the count of Ones to 0 to check again.
        countOnesByRow = 0;
        // space each row
        cout << endl;
    }
    cout << endl;
    
    cout << "The total number of 1\'s is: " << countAllOnes<< endl;

    cout << "Most ones in a row: " << mostOnes << endl;
    
    cout << "Row: " << rowX + 1 << " is the first row that has the most 1s.\n";
    return 0;
}
