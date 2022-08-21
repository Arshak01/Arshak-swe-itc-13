/**
 * @file bubbleSort.hpp
 * @author Arshak Badalyan (arshak.badalyan.im@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief  Bubble sort algorithm.
 * 
 * @tparam T : Generic type.
 * @param arr : Get array as param.
 * @param n  :  Get length of array.
 */
template <typename T>
void bubbleSort(T* arr, int n){
	bool swap = true;
	T temp;
	while(swap) {
		swap = false;
		for(int i = 0; i < n-1 ; ++i) {
			if(arr[i] > arr[i+1]) {
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				swap = true;
			}
		}
	}
}
