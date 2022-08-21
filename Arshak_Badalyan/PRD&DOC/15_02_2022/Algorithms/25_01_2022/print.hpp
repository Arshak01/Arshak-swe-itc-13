/**
 * @file print.hpp
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
 * @brief Print function which get  two arguments.
 *
 * @tparam T : Generic type.
 * @param arr  :  get a array as a argument.
 * @param n  : get a lenght of array.
 */
template <typename T>
void print(T* arr, int n) {
	for(int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
