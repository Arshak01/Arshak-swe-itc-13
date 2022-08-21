#include <iostream>
#include "header.hpp"


void insertionSort(int* arr, int size) {
	for (int i = 1 ; i < size; i++) {
		int min = arr[i];
		int count = i - 1;
		while (count >= 0 && arr[count] > min){
			arr[count + 1] = arr[count];
			count--;
		}
		arr[count+1] = min;
	}
}

