#include <iostream>
#include "sorting.hpp"

void shellSort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; ++i) {
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j-=gap)
				arr[j] = arr[j - gap];
			
			arr[j] = temp;
		}
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
