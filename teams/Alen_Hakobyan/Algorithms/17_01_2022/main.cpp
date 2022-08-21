#include <iostream>
#include <chrono>
#include "sorts.h"
using namespace std::chrono;

auto start = high_resolution_clock::now();
int main() {
	int size = 6;
	int arr[size] = {75,58,49,35,94,22};
	std::cout << "Array elements befor merge sort is : ";
	print(arr,size);
	mergeSort(arr,0,size-1);
	std::cout << "Array elements after merge sort is : ";
	print(arr,size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	print(arr,size);
	std::cout << "Function time is : " << duration.count() << std::endl;

    return 0;
}
