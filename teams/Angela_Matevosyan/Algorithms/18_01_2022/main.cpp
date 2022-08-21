#include <iostream>
#include "sorting.hpp"

int main() {
	const int n = 5;
	int arr[n] = {22, 11, 18, 26, 12};

	std::cout << "Unsorted Array: ";
	printArray(arr, n);

	std::cout << "Sorted by Shell Sort: ";
	shellSort(arr, n);
	printArray(arr, n);

	int arr2[n] = {8, 5, 36, 24, 3};
	std::cout << "Unsorted Array: ";
	printArray(arr2, n);

	std::cout << "Sorted by Quick Sort: ";
	quickSort(arr2, 0, (n - 1));
	printArray(arr2, n);

	return 0;
}
