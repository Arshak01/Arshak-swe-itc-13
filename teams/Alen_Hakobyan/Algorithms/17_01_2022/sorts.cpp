#include <iostream>

void merge(int* arr, int left, int mid, int right) {
	int arr1Size = mid - left + 1;
	int arr2Size = right - mid;
	int* subArr1 = new int[arr1Size];
	int* subArr2 = new int[arr2Size];
	for(int i = 0; i < arr1Size; ++i) {
		subArr1[i] = arr[left + i];
	}
	for(int j = 0; j < arr2Size; ++j) {
		subArr2[j] = arr[mid + 1 + j];
	}
	int indexArr1 = 0;
	int indexArr2 = 0;
	int indexArr = left;
	while(indexArr1 < arr1Size && indexArr2 < arr2Size) {
		if(subArr1[indexArr1] <= subArr2[indexArr2]) {
			arr[indexArr] = subArr1[indexArr1];
			indexArr1++;
		}
		else {
			arr[indexArr] = subArr2[indexArr2];
			indexArr2++;
		}
		indexArr++;
	}
	while(indexArr1 < arr1Size) {
		arr[indexArr] = subArr1[indexArr1];
		indexArr1++;
		indexArr++;
	}
	while(indexArr2 < arr2Size) {
		arr[indexArr] = subArr2[indexArr2];
		indexArr2++;
		indexArr++;
	}
}

void mergeSort(int* arr, int left, int right) {
	if(left < right) {
		int	mid = left + (right - left) / 2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}

void print(int* arr, int size) {
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
