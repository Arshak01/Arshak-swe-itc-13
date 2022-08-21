/**
 * @file bigOTime.hpp
 * @author Arshak badalyan (arshak.badalyan.im@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <chrono>
#include "../Shell/shellSort.hpp"
#include "../Quick/quickSort.hpp"

using namespace std::chrono;

/**
 * @brief  Call shell sort function
 * 
 * @tparam T  :  generic type of array.
 * @param arr  : array as a argument.
 * @param n  :  length of array.
 */
template <typename T>
void shell(T arr, int n) {
    std::cout << "*** ShellSort  ***" << std::endl;
    shellSort(arr, n);
}

/**
 * @brief  Call quick sort function 
 * 
 * @tparam T  : generic type of array.
 * @param arr  : array as aargument.
 * @param l  : first element from array.
 * @param n  : length of array.
 */
template <typename T>
void quick(T* arr,int l, int n) {
    std::cout << "*** QuickSort ***" << std::endl;
    quickSort(arr, l, n);
}

/**
 * @brief  CountTime function , which call sorting functions and count time.
 * 
 * @tparam T  : generic type.
 * @param arr  :  array as a arrgument.
 * @param n  :  length of array.
 * @return int : return int type  
 */
template <typename T>
int  countTime (T* arr, int n) {
	int l = 0;
	
	///@note startS, startQ : get current time before call function from <chrono> lib.
	///@note stopS, stopQ : get current time after call function  from <chrono> lib.
	///@note durationS, durationQ : get current time  different from stop and start time.
	
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
