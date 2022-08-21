#include <iostream>
#include <chrono>
#include "../Shell/shellSort.hpp"
#include "../Quick/quickSort.hpp"

using namespace std::chrono;

template <typename T>
void shell(T arr, int n) {
    std::cout << "*** ShellSort  ***" << std::endl;
    shellSort(arr, n);
}

template <typename T>
void quick(T* arr,int l, int n) {
    std::cout << "*** QuickSort ***" << std::endl;
    quickSort(arr, l, n);
}


template <typename T>
int  countTime (T* arr, int n) {
	int l = 0;
	
	auto startS = high_resolution_clock::now();
	shell(arr, n);
	auto stopS = high_resolution_clock::now();
	auto durationS = duration_cast<microseconds>(stopS - startS);
	std::cout << "Duration : " << durationS.count() << std::endl;
	
	auto startQ = high_resolution_clock::now();
	quick(arr, l, n-1);
	auto stopQ = high_resolution_clock::now();
	auto durationQ = duration_cast<microseconds>(stopQ - startQ);
	std::cout << "Duration : " << durationQ.count() << std::endl;
	
	return 0;
}
