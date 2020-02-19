// Write a function that shuffles the rows in a two-dimensional array using the following header:
// void shuffle(int m[][])
// Write a test program that shuffles the following matrix:
// int m[][]={{2,1},{5,6},{9,10},{4,3},{8,7}};

#include <iostream>
#include <iomanip>
#include <cstdlib> // gives us the random generator function

using namespace std;

void shuffle(int m[][2]);

const int MIN_VALUE = 0;
const int MAX_VALUE = 4;
const int ROWS = 5;
const int COLS = 2;

int main() {
    int m[5][2]={{2,1},{5,6},{9,10},{4,3},{8,7}};
    unsigned seed = time(0);
    srand(seed);
    cout << "Random 2D array shuffler.\n";
    cout << "\nThe unshuffled array is:\n";
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < COLS; l++) {
            cout << setw(4) << m[k][l];
        }
        cout << endl;
    }
    
    shuffle(m);
    
    cout << "\nThe shuffled array is now:\n";
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < COLS; l++) {
            cout << setw(4) << m[k][l];
        }
        cout << endl;
    }
    return 0;
}
void shuffle(int m[][2]) {
    int temp1, temp2;
    for (int x = 0; x < ROWS; x++) {
        int random = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        for (int y = 0; y < COLS; y++) {
            temp1 = m[x][y];
            temp2 = m[random][y];
            m[random][y] = temp1;
            m[x][y] = temp2;
        }
    }
}
