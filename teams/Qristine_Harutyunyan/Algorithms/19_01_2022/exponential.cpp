#include <iostream>


int min(int a, int b){
	return (a <= b)? a : b;
}

int binSearch(int* arr, int l, int r, int x){
	if(r >= l){
		int mid = l + (r - l)/2;

		if(arr[mid] == x) {
			return mid;
		}
		if(arr[mid] > x){
			return binSearch(arr, l, mid - 1, x);
		} else {
			return binSearch(arr, mid + 1, r , x);
		}
	} else {
		return -1;
	}
}
			

int expSearch(int* arr, int size, int x) {
	if(arr[0] == x) {
		return 0;
	}
	int i = 1;
	while(i < size && arr[i] <= x) {
		i = i * 2;
	}
	return binSearch(arr, i/2, min(i, size - 1), x);
}

void print(int* arr, int size, int x){
	if(expSearch(arr, size, x) == -1){
		std::cout << "There is not " << x << " in array" << std::endl;
	} else {
		std::cout << x << " is in index " << expSearch(arr, size, x);
	}
}
