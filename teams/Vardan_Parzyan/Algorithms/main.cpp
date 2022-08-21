#include <iostream>
#include <chrono>
#include "header.hpp"

using namespace std::chrono;

int main(){
	int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int size = sizeof(array)/sizeof(array[0]);
	std::cout << "Starting bubble sort" << std::endl;
	auto start = high_resolution_clock::now();
	bubbleSort(array,size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	arrPrint(array,size);
	std::cout << "bubble sort complete in : " << duration.count() << " microseconds\n" <<std::endl;
	std::cout << "Starting Insertion Sort" << std::endl;
	start = high_resolution_clock::now();
	insertionSort(array,size);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	arrPrint(array,size);
	std::cout << "Insertion sort complete in : " << duration.count() << " microseconds\n" <<std::endl;
	std::cout << "Starting Seleftion Sort" << std::endl;
	start = high_resolution_clock::now();
	selectionSort(array,size);
	stop = high_resolution_clock::now();
	arrPrint(array,size);
	std::cout << "Selection sort complete in : " << duration.count() << " microseconds\n" <<std::endl;
	return 0;
}

