/**
 * @file quickSort.hpp
 * @author Arshak badalyan (arshak.badalyan.im@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>


/**
 * @brief  Swap function to change  two element.
 * 
 * @tparam T  : generic type  variables.
 * @param l  :  left element from array.
 * @param r  : right element from array.
 * 
 */
template <typename T>
void swap(T* l, T* r) { 
	T temp = *l; 
	*l = *r; 
	*r = temp; 
} 


/**
 * @brief To get the Pivot value between first, last and middle element from array.
 * 
 * @tparam T   :  generic type variables.
 * @param arr  :  generic type  function and variables.
 * @param low  :  left element from array.
 * @param high :  right element from array.
 * @return int :  return result type of int.
 */
template <typename T>
int getPivot(T* arr, int low, int high) {
	int mid = (low + (high - low) + 1 /2);
	if((arr[high] < arr[low]) && (arr[high] > arr[mid])) {
		return high;
	} else if((arr[low] < arr[high]) && (arr[low] > arr[mid])) {
		return low;
	} else {
		return mid;
	}
}


/**
 * @brief  Partition function which  sort  element from array.
 * 
 * @tparam T   : generic type variables.
 * @param arr   : generic type  function and variables.
 * @param low  :  left element from array.
 * @param high : right element from array.
 * @return int  : return result type of int.
 */
template <typename T>
int partition (T* arr, int low, int high) {
	int pivot = arr[getPivot(arr,low,high)];
	int i = (low - 1); 

	for (int j = low; j <= high - 1; ++j) {  
		if (arr[j] < pivot) { 
			i++;   
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
    
	return (i + 1); 
} 



/**
 * @brief  @Quicksort is a recursive function which also can call partition function.
 * 
 * @tparam T  : generic type variables.
 * @param arr  : generic type  function and variables.
 * @param low :  left element from array.
 * @param high : right element from array.
 * 
 */
template <typename T>
void quickSort(T arr[], int low, int high) { 
	if (low < high) { 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
    }
} 
  
