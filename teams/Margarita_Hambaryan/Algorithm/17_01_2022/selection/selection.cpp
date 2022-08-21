#include <iostream>

void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		int min_index = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
	}
}

void print(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
}

int main() {
	int arr[5] = {5, 8, 2, 7, 1};
	unsigned int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Before sorting.\n";
	print(arr, n);
	std::cout << "\nAfter sorting.\n";
	selectionSort(arr, n);
	print(arr, n);
	std::cout << "\n";
	return 0;
}
