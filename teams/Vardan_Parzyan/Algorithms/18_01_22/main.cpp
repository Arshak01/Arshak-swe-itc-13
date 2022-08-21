#include <iostream>
#include <chrono>
#include "functions.hpp"

using namespace std::chrono;

int main() {
	int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int size = sizeof(array) / sizeof(array[0]);
  	std::cout << "Starting quick sort \n";
  	auto start = high_resolution_clock::now();
  	quickSort(array, 0, size - 1);
  	auto stop = high_resolution_clock::now();
  	auto duration = duration_cast<microseconds>(stop - start);
  	printArray(array, size);
  	std::cout << "Quick sort complete in : " << duration.count() << " microseconds\n" <<std::endl;
	int array2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	std::cout << "starting shell sorting: \n";
	shellSort(array, size);
  	printArray(array, size);
  	std::cout << "Shell sort sort complete in :"<< duration.count() << " microseconds\n" <<std::endl;;
  	return 0;
}

