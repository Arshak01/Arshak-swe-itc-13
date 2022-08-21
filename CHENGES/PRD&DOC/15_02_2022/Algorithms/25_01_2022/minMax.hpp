/**
 * @file minMax.hpp
 * @author Arshak Badalyan (arshak.badalyan.im@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief MinMax is a recursion function to find minimum and maximum elements from arrays.
 * 
 * @tparam T : Generic type
 * @param arr : Get array
 * @param l  :  Get first index of array.
 * @param r  : Get last index of array.
 * @param min : Get minimum element of array
 * @param max : Get maximum element of array
 */
template <typename T>
void minMax(T* arr, int l, int r, T& min, T& max) {
	if (l == r) {
		min = max = arr[l];
	} else {
		T mid = l + (r - l) / 2;
		T leftMin;
		T leftMax;
		T rightMin;
		T rightMax;

		minMax(arr, l, mid, leftMin, leftMax);
		minMax(arr, mid + 1, r, rightMin, rightMax);

		if (leftMin < rightMin) {
			min = leftMin;
		} else {
			min = rightMin;
		}

		if (leftMax > rightMax) {
			max = leftMax;
		} else {
			max = rightMax;
		}
	}
}
