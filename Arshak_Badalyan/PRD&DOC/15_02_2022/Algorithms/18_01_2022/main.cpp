/**
 * @file main.cpp
 * @author Arshak Badalyan (arshak.badalyan.im@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "./Print/print.hpp"
#include "./BigOTime/bigOTime.hpp"

/**
 * @brief  Main function. Inside of  that give length of array and creat  array using random elements. 
 * Afther that call print and countTime function , which give arguments.
 * 
 * @return int  : return int number.
 */
int main() {
	///@note size : Length of array.
	int size;
	std::cout << "Enter the size of array : ";
	std::cin >> size;
	int arr[size];
	std::cout << std::endl;

	for(int i = 0;i < size; ++i) {
		arr[i]=rand()%60;  ///@note rand() :  Random function to generate some numbers.
	}
	///@note n : Get length of array.
	int n = sizeof(arr)/sizeof(arr[0]);
	print(arr, n);
	countTime(arr,n);
	print(arr, n);

	return 0;
}
