#include <iostream>
using namespace std;
// use string for selection sort

int main() {
	bool needNextPass = true;
	int size = 5;
	int arr[] = { 5, 6, 10, 2, 1 };
	cout << "The unsorted array is ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 1; i < size; i++) {
		needNextPass = false;
		for (int j = 0; j < size - i; j++) {
			// if 0 is greater than 0 + 1 then swap 
			if (arr[j] > arr[j + 1]) {
				// swap(arr[j], arr[j + 1]);
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
				needNextPass = true;
			}
		}
	}
	cout << "The enhanced bubble sorted array is now ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}