#include <iostream>

void shellSort(int* arr, int size) {
	
	for(int gap = size / 2; gap > 0; gap = gap / 2){
		for(int i = gap; i < size; ++i){
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j = j - gap){
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

void print(int* arr, int size){
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " " ;
	}
	std::cout << std::endl;
}
