/**
 * @file selectionSort.hpp
 * @author Arshak Badalyan (arshak.badalyan.im@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Selection sort 
 * 
 * @tparam T : Generic type.
 * @param arr : Get array as a param.
 * @param n : Get length of array.
 */
template <typename T>
void selectionSort(T* arr, int n) {
	int position = 0;
	int minIndex;
	T temp;

	while(position < n){
		minIndex = position;
		for(int i = position; i < n; ++i) {
			if(arr[i] < arr[minIndex]) {
				minIndex = i;
				temp = arr[i];
				arr[i] = arr[position];
				arr[position] = temp;
			}
		}
		position++;
		minIndex++;

	}
}
