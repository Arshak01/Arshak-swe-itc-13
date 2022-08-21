#include <iostream>
#include <chrono>
#include "ins_merge.hpp"

using namespace std::chrono;

int main() {	     
	int const size = 5;
	int arr[size] = {5, 2, 8, 3, 1};
	int arr1[size] = {5, 1, 75, 65, 4};

        std::cout << "Unsorted array" << std::endl;
	print(arr, size);
	std::cout << "Sorted array" << std::endl;

	auto start = high_resolution_clock::now();
	insertSort(arr, size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(start - stop);
	print(arr, size); 
	std::cout <<"Insertion sort " << duration.count() <<"m_secods" << std::endl;


	std::cout << std::endl;
	std::cout << "Unsorted array" << std::endl;
	print(arr1, size);
	std::cout << "Sorted array" << std::endl;
	
	auto start1 = high_resolution_clock::now();
	mergeSort(arr1, 0, size - 1);
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(start1 - stop1);
	print(arr1, size); 
	std::cout <<"Merge sort " << duration.count() <<"m_secods" << std::endl;

	return 0;
}

