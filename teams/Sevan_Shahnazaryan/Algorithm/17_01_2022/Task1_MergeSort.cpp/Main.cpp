#include <iostream>
#include "MergeSort.hpp"

int main() {
	const int size = 500;
	int *arr = MergeSort::randomGen(size);
	//MergeSort::merge(arr, 0, 1, 2, size);
	std::cout << "\nArray before Merge Sort\n" << std::endl;
	MergeSort::print(arr, size);
	MergeSort::sort(arr, 0, size-1, size);
	std::cout << "\nArray after Merge Sort\n" << std::endl;
	MergeSort::print(arr, size);
//MergeSort::print(arr, size);
//delete[] arr;
//arr = NULL;
	return 0;
}
