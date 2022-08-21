#include <iostream>
#include "Quick.hpp"

int* Quick::sort(int *arr, int size) {
	int pivot = arr[0];
	int *arr1 = new int[size];
	int *arr2 = new int[size];
	int j = 0;
	int k = 0;
	if(size > 1) {
		for(int i = 1; i < size; ++i) {
			if(arr[i] < pivot) {
				arr1[j] = arr[i];
				++j;
			} else {
				arr2[k] = arr[i];
				++k;
			}
		}
		arr1 = sort(arr1, j);
		arr2 = sort(arr2, k);
	}
	int *arr3 = merge(arr1, arr2, j, k, pivot);
	delete[] arr1;
	delete[] arr2;
	return arr3;

}

int* Quick::merge(int *arr1, int *arr2, int size1, int size2, int pivot) {
	int newSize = size1 + size2 + 1;
	int *arr = new int[newSize];
	for(int i = 0; i < size1; ++i) {
		arr[i] = arr1[i];
	}
	arr[size1] = pivot;
	for(int i = size1 + 1, j = 0; i < newSize; ++i, ++j) {
		arr[i] = arr2[j];
	}
	return arr;
}

int* Quick::randomGen(int size) {
    int *arr = new int[size];
    for(int i = 0; i < size; ++i) {
        arr[i] = rand() % (size*2) + 1;
    }
    return arr;
}

void Quick::print(int *arr, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b" << ' ' << std::endl;// to remove the last ','
}
