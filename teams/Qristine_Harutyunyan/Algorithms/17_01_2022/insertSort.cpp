#include <iostream>

void insertSort (int* arr, int size){
	int i, j, key;
	for (int i = 1; i < size; ++i){
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void print(int* arr, int size){
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
