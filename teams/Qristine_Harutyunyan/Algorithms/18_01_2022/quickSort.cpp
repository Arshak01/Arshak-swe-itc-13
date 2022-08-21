#include <iostream>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;

}

int partition(int* arr, int lowInd, int highInd){
	int pivot = arr[highInd];
	int i = lowInd - 1;
	for(int j = lowInd; j <= highInd - 1; ++j) {
		if(arr[j] < pivot){
			i++;
			swap(&arr[j], &arr[i]);
		}
	}
	swap(&arr[i + 1], &arr[highInd]);
	return i + 1;
}


void quickSort(int* arr, int low, int high){
	if (low < high){
		int p = partition(arr, low, high);

		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}
