#include <iostream>
#include <limits.h>

int findMin(int *arr, const int size, int i = 0, int min = INT_MAX) {
	if(i >= size) {
		return min;
	} else if(arr[i] < min) {
		min = arr[i];
	}
	return findMin(arr, size, i + 1, min);
}

int findMax(int *arr, const int size, int i = 0, int max = INT_MIN) {
	if(i >= size) {
		return max;
	} else if(arr[i] > max) {
		max = arr[i];
	}
	return findMax(arr, size, i + 1, max);
}

void print(int *arr, const int size) {
	std::cout << "arr = {";
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b" << ' ' << std::endl;
}

int main() {
	const int size = 10;
	int arr[size] = {98, 23, 11, 105, 161, 1, 9, 141, 12, 5};
	print(arr, size);
	std::cout << "min = " << findMin(arr, size) << std::endl;
	std::cout << "max = " << findMax(arr, size) << std::endl;
	return 0;
}
