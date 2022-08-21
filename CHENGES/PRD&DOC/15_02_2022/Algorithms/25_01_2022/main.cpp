/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "./print.hpp"
#include "./minMax.hpp"

/**
 * @brief  Main function, where  generate array by length, which input after running.
 * 
 * @return int 
 */
int main() {
	int size;
	std::cout << "Enter the size of array : ";
	std::cin >> size;
	int arr[size];
	std::cout << std::endl;

	for(int i = 0;i < size; ++i) {
		arr[i]=rand()%100; 
	}

	int r = sizeof(arr) / sizeof(arr[0]);

	int l = 0;
	///@brief min, max : var for minimum and maximum elements in arrays.
	int min;
	int max;
	print(arr, r);
	minMax(arr, l, r-1, min, max);	

	std::cout << "Min : " << min << std::endl;
	std::cout << "Max : " << max << std::endl;

	return 0;

}
