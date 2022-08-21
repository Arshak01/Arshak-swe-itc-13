/**
 * @file insertionSort.hpp
 * @author Arshak Badalyan (arshak.badalyan.im@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief  Insertion sort algorithm.
 * 
 * @tparam T : Generic type.
 * @param arr : Get array as param.
 * @param n  :  Get length of array.
 */
template <typename T>
void insertionSort(T* arr, int n) {
	T temp;
	for(int i = 1; i < n; ++i) {
		while(arr[i] < arr[i-1] && i > 0) {
			if(arr[i] < arr[i-1]) {
				temp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = temp;	
			}
			i--;
		}
	}
}
