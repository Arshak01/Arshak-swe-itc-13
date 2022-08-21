/**
 * @file shellSort.hpp
 * @author Arshak Badalyan (arshak.badalyan.im@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <cmath>

/**
 * @brief 
 * 
 * @tparam T : Generic type 
 * @param arr  : Get array.
 * @param n  : Get length of array.
 */
template <typename T>
void shellSort(T* arr, int n) {
	T temp;
	///@note  gap : Count gap by using sqrt() function from <cmath> lib.
	int gap = sqrt(n);
	int j;

	///@note  gap : Count gap by using sqrt() function from <cmath> lib.
	for(int i = n; gap > 0; gap/=2) {
		for(int i = gap; i < n; ++i) {
			int j = i;	
			temp = arr[i];	
			while(temp < arr[j-gap] && j >= gap) {
				arr[j] = arr[j-gap];
				j = j-gap;
			}
			arr[j] = temp;
		}	
	}
}
