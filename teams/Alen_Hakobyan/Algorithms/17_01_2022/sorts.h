#ifndef SORTS_H
#define SORTS_H

void subArr(int* arr, int left, int mid, int right);
void merge(int* subArr1, int* subArr2, int arr1Size, int arr2Size, int left);
void mergeSort(int* arr, int left, int right);
void print(int* arr, int size);

#endif
