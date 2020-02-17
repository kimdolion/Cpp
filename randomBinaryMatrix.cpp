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
    int count = 0;
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
            int randomLimit = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            matrix[x][y] = randomLimit;
            cout << setw(5) << matrix[x][y];
            if (matrix[x][y] == 1) {
                count += 1;
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "The total number of 1\'s is: " << count << endl;
    // cout << "Row: " << rowX << "\tColumn: "<< columnY << " has the most 1s.\n";
    return 0;
}
