#include <iostream>
#include "header.hpp"

void selectionSort(int* arr, int size){
	for (int i = 0 ; i < size -1; i++ ){
		int max = i;
		for (int j = i+1; j < size; j++){
			if(arr[j] > arr[max] ){
				max = j;
			}
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
}

