#include <iostream>
#include "mergeSort.h"

void merge(int arr[], int left, int right, int mid) {
	int c[30];
	int i = left;
	int k = left;
	int j = mid + 1;

	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			c[k] = arr[i];
			k++;
			i++;
		} else {
			c[k] = arr[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		c[k] = arr[i];
		k++;
		i++;
	}

	while (j <= right) {
		c[k] = arr[j];
		k++;
		j++;	
	}

	for (i = left; i < k; ++i) {
		arr[i] = c[i];
	}
}

void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, right, mid);
	}
	return;
}
