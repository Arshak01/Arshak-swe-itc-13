#include <iostream>
#include <cmath>
#include "ShellSort.hpp"

void ShellSort::sort(int *arr, int size) {
	int gap = std::sqrt(size);
	while(gap >= 1) {
		int j = gap;
		for(int i = gap; i < size; ++i) {
			j = i;
			while(j - gap >= 0 && arr[j - gap] > arr[j]) {
				int tmp = arr[j - gap];
				arr[j - gap] = arr[j];
				arr[j] = tmp;
				j = j - gap;
			}
		}
		gap/=2;
	}
}

int* ShellSort::randomGen(int size) {
    int *arr = new int[size];
    for(int i = 0; i < size; ++i) {
        arr[i] = rand() % (size*2) + 1;
    }
    return arr;
}

void ShellSort::print(int *arr, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b" << ' ' << std::endl;// to remove the last ','
}
