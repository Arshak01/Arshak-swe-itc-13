#include <iostream>



int min(int a, int b) {
	return (a >= b)? b : a;
}

int max(int a, int b) {
	return (a >= b)? a : b;
}

int findMin(int* arr, int n){
	if (n == 1){
		return arr[0];
	}
	return min(arr[n - 1], findMin(arr, n - 1));
}

int findMax(int* arr, int n) {
	if (n == 1){
		return arr[0];
	}
	return max(arr[n - 1], findMax(arr, n - 1));
}

void print(int* arr){
	int n = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


int main() {
	int arr[] = {4, 7, 35, 95, 1, -5, 0, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	std::cout << "Print array" << std::endl;
	std::cout << "Max of array is " << findMax(arr, n) << std::endl;
	std::cout << "Min of array is " << findMin(arr, n) << std::endl;
	
	return 0;
}
