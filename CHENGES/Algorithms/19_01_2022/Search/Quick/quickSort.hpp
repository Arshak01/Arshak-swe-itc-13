#include <iostream>
  
template <typename T>
void swap(T* l, T* r) { 
	T temp = *l; 
	*l = *r; 
	*r = temp; 
} 

template <typename T>
int getPivot(T* arr, int low, int high) {
	int mid = (low + (high - low) + 1 /2);
	
	if((arr[high] < arr[low]) && (arr[high] > arr[mid])) {
		return high;
	} else if((arr[low] < arr[high]) && (arr[low] > arr[mid])) {
		return low;
	} else {
		return mid;
	}
}
  
template <typename T>
int partition (T* arr, int low, int high) {

	int pivot = arr[getPivot(arr,low,high)];
	int i = (low - 1); 

	for (int j = low; j <= high - 1; ++j) {  
		if (arr[j] < pivot) { 
			i++;  
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
    
	return (i + 1); 
} 

template <typename T>
void quickSort(T arr[], int low, int high) { 
	if (low < high) { 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
    }
} 
  
