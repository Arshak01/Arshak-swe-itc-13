#include "SelectionSort.hpp"
#include <iostream>
#include <cstdlib>

int SelSort::min(int *arr, int size, int startingPoint) {
	int min = arr[startingPoint];
	int minIndex = startingPoint;
	for(int i = startingPoint; i < size; ++i) {
		if(min > arr[i]) {
			min = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void SelSort::sort(int *arr, int size) {
	int tmp = 0;
	int minIndex = 0;
	for(int i = 0; i < size; ++i) {
		tmp = arr[i];
		minIndex = min(arr, size, i);
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
}

int* SelSort::randomGen(int size) {
	int *arr = new int[size];
	for(int i = 0; i < size; ++i) {
		arr[i] = rand() % 1000 + 1;
	}
	return arr;
}

void SelSort::print(int *arr, int size) {
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b" << ' ' << std::endl;// to remove the last ','
}
