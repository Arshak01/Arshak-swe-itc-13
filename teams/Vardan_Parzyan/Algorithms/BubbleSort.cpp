#include <iostream>
#include "header.hpp"


void bubbleSort(int* arr, int size){
	bool isSorted = false;
	while(!isSorted){
		isSorted = true;
	for(int i = 0; i < size - 1; i++){
		if(arr[i] < arr[i+1]){
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			isSorted = false;
		}
	}
	}
}

void arrPrint(int* arr, int size){
	for(int i = 0; i < size; i++){
		std::cout << " | " << arr[i]; 	
	}
	std::cout <<" | "<< std::endl;
}
