#include <iostream>
#include <chrono>
#include "../Bubble/bubbleSort.hpp"
#include "../Selection/selectionSort.hpp"
#include "../Insertion/insertionSort.hpp"
#include "../Merge/mergeSort.hpp"

using namespace std::chrono;

template <typename T>
void bubble(T arr, int n) {
	std::cout << "*** BubbleSort ***" << std::endl;
	bubbleSort(arr, n);
}

template <typename T>
void select(T arr, int n) {
    std::cout << "*** SelectionSort ***" << std::endl;
    selectionSort(arr, n);
}

template <typename T>
void insert(T arr, int n) {
    std::cout << "*** InsertionSort  ***" << std::endl;
    insertionSort(arr, n);
}

template <typename T>
void merge(T arr,int n, int l) {
    std::cout << "*** MergeSort ***" << std::endl;
    mergeSort(arr, l,  n);
}


template <typename T>
int  countTime (T* arr,int n, int l = 0) {

	auto startB = high_resolution_clock::now();
	bubble(arr, n);
	auto stopB = high_resolution_clock::now();
	auto durationB = duration_cast<microseconds>(stopB - startB);	
	std::cout << "Duration : " << durationB.count() << std::endl;

	auto startS = high_resolution_clock::now();
	select(arr, n);
	auto stopS = high_resolution_clock::now();
	auto durationS = duration_cast<microseconds>(stopS - startS);
	std::cout << "Duration : " << durationS.count() << std::endl;

	auto startI = high_resolution_clock::now();
	insert(arr, n);
	auto stopI = high_resolution_clock::now();
	auto durationI = duration_cast<microseconds>(stopI - startI);
	std::cout << "Duration : " << durationI.count() << std::endl;

	auto startM = high_resolution_clock::now();
	merge(arr, l, n);
	auto stopM = high_resolution_clock::now();
	auto durationM = duration_cast<microseconds>(stopM - startM);
	std::cout << "Duration : " << durationM.count() << std::endl;
	
	return 0;
}
