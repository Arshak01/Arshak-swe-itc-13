#include <iostream>

template <typename T>
void merge(T* arr, T l,T mid,T r) {
	T n1 = mid - l + 1;
	T n2 = r - mid;

	T* left = new T[n1];
	T* right = new T[n2];

	for (int i = 0; i < n1; ++i) {
		left[i] = arr[l + i];
	}
	for (int j = 0; j < n2; ++j) {
		right[j] = arr[mid + 1 + j];
	}

	int i = 0; 
	int	j = 0; 
	int k = l;
	
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		} else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}
    
	while (i < n1) {
		arr[k] = left[i];
		i++;
		k++;
	}
    
	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

template <typename T>
void mergeSort(T* arr,T l,T r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}

