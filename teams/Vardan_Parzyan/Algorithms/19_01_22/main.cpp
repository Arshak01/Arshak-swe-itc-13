#include <iostream>
#include <chrono>
#include "functions.hpp"

using namespace std::chrono;

int main() {
	int arr[] = { 5, 11, 18, 20, 25, 28, 29, 33, 39, 45, 56, 88 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int key = 39;
	auto start = high_resolution_clock::now();
	int element = interpolationSearch(arr, 0, size - 1, key);
	auto stop = high_resolution_clock::now();
  	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Interpolation search complete in : " << duration.count() << " microseconds \n";
	if (element != -1){
		std::cout << "Element index is " << element << std::endl;
	} else {
		std::cout << "The search has not given any results." << std::endl;
	}
	
	return 0;
}

