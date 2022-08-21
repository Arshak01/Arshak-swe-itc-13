#include <iostream>
#include "MergeSort/mergeSort.h"
#include "SelectionSort/selectionSort.h"
#include <chrono>

int main() {
	int arraySize  = 20;
	int array1[arraySize] = {8, 4, 19, 48, 12, 9, 10, 5, 21, 78, 79, 41, 13, 7, 54, 91, 33, 64, 11, 84};

	std::cout << "The array before sorting." << std::endl; 
	for (int i = 0; i < arraySize; ++i) {
		std::cout << array1[i] << " ";
	}	
	std::cout << std::endl;

	auto start1 = std::chrono::high_resolution_clock::now();
	selectionSort(array1, arraySize);
	auto stop1 = std::chrono::high_resolution_clock::now();
	auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop1 - start1);
	std::cout << "The sorted array using Selection Sort." << std::endl; 
	for (int i = 0; i < arraySize; ++i) {
		std::cout << array1[i] << " ";
	}	
	std::cout << std::endl;
	std::cout << "Duration: " << duration1.count() << " nanoseconds." << std::endl;

	int array2[arraySize] = {8, 4, 19, 48, 12, 9, 10, 5, 21, 78, 79, 41, 13, 7, 54, 91, 33, 64, 11, 84};
	int left = 0;
	int right = arraySize - 1;

	auto start2 = std::chrono::high_resolution_clock::now();
	mergeSort(array2, left, right);
	auto stop2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop2 - start2);
	std::cout << "The sorted array using Merge Sort." << std::endl; 
	for (int i = 0; i < arraySize; ++i) {
		std::cout << array2[i] << " ";
	}	
	std::cout << std::endl;
	std::cout << "Duration: " << duration2.count() << " nanoseconds." << std::endl;

	return 0;
}
