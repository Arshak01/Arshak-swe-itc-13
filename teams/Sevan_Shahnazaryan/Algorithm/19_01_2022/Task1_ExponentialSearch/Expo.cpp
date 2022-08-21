#include <iostream>
#include "Expo.hpp"
#include <cmath>

int Expo::search(int *arr, int size, int elem) {
	int i = 0;
	if(arr[size - 1] == elem) {
		return size - 1;
	}
	while(i < size && arr[i] < elem) {
		i = pow(2, i);
	}
	return binarySearch(arr, size, elem, sqrt(i), i);
}

int Expo::binarySearch(int *arr, int size, int elem, int left, int right) {
	int mid = 0;
	while(left <= right) {
		mid = left + ((right - left) / 2);
		if(arr[mid] == elem) {
			return mid;
		} else if(arr[mid] > elem) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	std::cout << "No such element in the array" << std::endl;
	return -1;

}

int* Expo::arrGen(int size) {
    int *arr = new int[size];
	int j = 1;
    for(int i = 0; i < size; ++i) {
        arr[i] = rand() % (j*2) + j;
		j *= 2;
    }
    return arr;
}

void Expo::print(int *arr, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b" << ' ' << std::endl;// to remove the last ','
}
