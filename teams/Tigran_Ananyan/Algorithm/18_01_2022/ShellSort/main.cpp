#include  <iostream>
#include "ShellSort.hpp"
#include <chrono>
using namespace std::chrono;

auto start = high_resolution_clock::now();
int main() {
    int arr[] = {15, 2, 26, 32, 1, 11, 50, 20};
    int i;
    int n = sizeof(arr)/sizeof(arr[0]);

    std::cout << "\nArray before sorting: \n";
    printArray(arr, n);
    shellSort(arr, n);
    std::cout << "\nArray after sorting: \n";
    printArray(arr, n);
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "\nSorting time is  " << duration.count() << " microseconds" << std::endl;


    return 0;
}
