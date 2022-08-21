#include <iostream>
#include "selectionSort.h"

void swap(int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void selectionSort(int array[], int n) {
	int current = 0;
	int tmp;
	for (int i = 0; i < n - 1; i++) {
		tmp = array[i];
		for (int j = i + 1; j < n; j++) {
			if (tmp > array[j]) {
				tmp = array[j];
				current = j;
			}
		}
		if (array[i] != array[current]) {
			swap (&array[i], &array[current]);
		}
	}
}
