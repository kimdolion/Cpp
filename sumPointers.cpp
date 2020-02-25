#include <iostream>

using namespace std;

void getNumbers(int* , int);
int sumNumbers(int*, int);

int main()
{
    const int SIZE = 5;
    int sumArray[SIZE];
    cout << "You're adding " << SIZE << " numbers.\n"; // returns user value
    getNumbers(sumArray, SIZE);
    cout << "\n\nValue of sum is: " << sumNumbers(sumArray, SIZE) << endl;
    return 0;
}

void getNumbers(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << " to be added: ";
        cin >> arr[i];
    }

}
int sumNumbers(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *arr;
        arr++;
    }
    return sum;
}