#include <iostream>
#include "QuickSort.hpp"
#include <chrono>
using namespace std::chrono;

auto start = high_resolution_clock::now();
int main() {
    int arr[10] = {12, 23, 2, 4, 6, 34, 56, 1, 5, 24};
    int l = sizeof(arr) / sizeof(arr[0]);
    std::cout << "\nBefore sorting: " << std::endl;
    printArr(arr, l);
    quickSort(arr, 0, l - 1);
    std::cout << "\nAfter sorting: " << std::endl;
    printArr(arr, l);
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "\nSorting time is " << duration.count() << " microseconds"  << std::endl;


    return 0;
    }
