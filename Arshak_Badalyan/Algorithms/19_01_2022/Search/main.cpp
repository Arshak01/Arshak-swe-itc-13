#include <iostream>
#include "./Print/print.hpp"
#include "./BigOTime/bigOTime.hpp"
#include "./Quick/quickSort.hpp"

int main() {
	int key;
	int size;
	int l = 0;
	std::cout << "Enter the size of array : ";
	std::cin >> size;
	int arr[size];
	std::cout << std::endl;

	for(int i = 0;i < size; ++i) {
		arr[i]=rand()%60; 
	}
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	quickSort(arr,l, n);	
	print(arr, n);
	std::cout << "Enter key : ";
	std::cin >> key;
	countTime(arr, l, n, key);

	return 0;
}
