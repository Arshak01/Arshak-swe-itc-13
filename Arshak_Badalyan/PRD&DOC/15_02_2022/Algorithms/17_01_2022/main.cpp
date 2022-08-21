/**
 * @file main.cpp
 * @author Arshak Badalyan (arshak.badalyan.im@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "./Print/print.hpp"
#include "./BigOTime/bigOTime.hpp"

/**
 * @brief  Main function for some sorting algorithms.
 * 
 * @return int  : retrun number type of int.
 */
int main() {
	int size;
	std::cout << "Enter the size of array : ";
	std::cin >> size;
	int arr[size];
	///@node rand : this is a function from iostream.Give random numbers.
	for(int i = 0;i < size; ++i) {
		arr[i]=rand()%100; 
	}
	
	int n = sizeof(arr)/sizeof(arr[0]);
	int l = 0;
	print(arr, n);
	countTime(arr,n);
	print(arr, n);

	return 0;
}
