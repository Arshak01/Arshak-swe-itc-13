/**
 * @file bigOTime.hpp
 * @author Arshak Badalyan (arshak.badalyan.im@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <chrono>
#include "../Bubble/bubbleSort.hpp"
#include "../Selection/selectionSort.hpp"
#include "../Insertion/insertionSort.hpp"
#include "../Merge/mergeSort.hpp"

using namespace std::chrono;

/**
 * @brief  Call bubble sort function and transfer as  arguments` arrays and length of array.
 * 
 * @tparam T  : Generic type.
 * @param arr  : Get array and transfer as  a argument.
 * @param n  : Get length of array.
 */
template <typename T>
void bubble(T arr, int n) {
	std::cout << "*** BubbleSort ***" << std::endl;
	bubbleSort(arr, n);
}

/**
 * @brief  Call selection sort function and transfer as  arguments` arrays and length of array.
 * 
 * @tparam T  : Generic type.
 * @param arr  : Get array and transfer as  a argument.
 * @param n  : Get length of array.
 */
template <typename T>
void select(T arr, int n) {
    std::cout << "*** SelectionSort ***" << std::endl;
    selectionSort(arr, n);
}

/**
 * @brief  Call insertion sort function and transfer as  arguments` arrays and length of array.
 * 
 * @tparam T  : Generic type.
 * @param arr  : Get array and transfer as  a argument.
 * @param n  : Get length of array.
 */
template <typename T>
void insert(T arr, int n) {
    std::cout << "*** InsertionSort  ***" << std::endl;
    insertionSort(arr, n);
}

/**
 * @brief Call merge sort function and transfer as  arguments` arrays, first index and length of array.
 * 
 * @tparam T : Generic type.
 * @param arr : Get array and transfer as  a argument.
 * @param n  : Get length of array. 
 * @param l : Get 0 as a first index of array
 */
template <typename T>
void merge(T arr,int n, int l) {
    std::cout << "*** MergeSort ***" << std::endl;
    mergeSort(arr, l,  n);
}

/**
 * @brief  Call CountTime function for count spand time every sorting functions and campare results. 
 * 
 * @tparam T : Generic type
 * @param arr : Get array and transfer as a argument.
 * @param n  : Get array length.
 * @param l  : Get 0 as a first  index of array.
 * @return int  : return number type of int.
 */
template <typename T>
int  countTime (T* arr,int n, int l = 0) {

	 

	/**
	 * @brief startB , startS, startI, startM : get current time before call function from <chrono> lib.\n
	 * @brief stopB, stopS, stopI, stopM : get current time after call function  from <chrono> lib.\n
	 * @brief durationB, durationS, durationI, durationM : get current time  different from stop and start time.
	 * 
	 */
	
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
