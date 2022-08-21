#include "shellSort.h"

void swap(int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void shellSort(int array[], int size) {
    int gap = size / 2;

    for (gap; gap >= 1; gap /= 2) {
        int j = gap;
        for(int i = gap; i < size; ++i) {
            j = i;
            while(j - gap >= 0 && array[j - gap] > array[j]) {
                swap(&array[j - gap], &array[j]);
                j = j - gap;
            }
        }
    }
}
