#include <iostream>
#include <cmath>
#include "MergeSort.hpp"

void MergeSort::sort(int *arr, int left, int right, int size) {
	int middle = (left + right) / 2;
	if(right - left > 1) {
		sort(arr, left, middle, size);
		sort(arr, middle+1, right, size);
	}
	merge(arr, left, middle, right, size);
}

void MergeSort::merge(int *arr, int left, int middle, int right, int size) {
	int i = left;
	int j = middle+1;
	int *tmp = new int[right - left + 1];
	int k = 0;
	while(k < right - left + 1){
		if(arr[i] < arr[j]) {
			temper(tmp, arr, &k, &i);
		} else {
			temper(tmp, arr, &k, &j);
		}
		if(j > right) {
			while(i <= middle) {
				temper(tmp, arr, &k, &i);
			}
		}
		if(i > middle) {
			while(j <= right) {
				temper(tmp, arr, &k, &j);
			}
		}
	}
	copy(arr, tmp, left, right);
}

void MergeSort::copy(int *arr1, int *arr2, int left, int right) {
    int i = left;
	for(int k = 0; k < right - left + 1; ++k) {
        arr1[i] = arr2[k];
        ++i;
    }
    delete[] arr2;
}

void MergeSort::temper(int *arr1, int *arr2, int *i1, int *i2) {
	arr1[*i1] = arr2[*i2];
	++*i1;
	++*i2;
}

int* MergeSort::randomGen(int size) {
    int *arr = new int[size];
    for(int i = 0; i < size; ++i) {
        arr[i] = rand() % (size*2) + 1;
    }
    return arr;
}

void MergeSort::print(int *arr, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b" << ' ' << std::endl;// to remove the last ','
}
