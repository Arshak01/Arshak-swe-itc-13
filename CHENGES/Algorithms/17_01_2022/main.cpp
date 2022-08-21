#include <iostream>
#include "./Print/print.hpp"
#include "./BigOTime/bigOTime.hpp"

int main() {
	int size;
	std::cout << "Enter the size of array : ";
	std::cin >> size;
	int arr[size];

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
