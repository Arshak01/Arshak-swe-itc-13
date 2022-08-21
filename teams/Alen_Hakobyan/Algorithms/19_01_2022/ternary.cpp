#include <iostream>

int ternary(int* arr, int left, int right, int number);

int main() {
	int size = 11;
	int number;
	int arr[size] = {5,7,9,13,14,18,20,35,37,40,55};
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Input number to find index : ";
	std::cin >> number;
	std::cout << "Index of " << number << " is : " << ternary(arr,0,size-1,number) << std::endl;
	return 0;
}

int ternary(int* arr, int left, int right, int number) {
	if(left <= right) {
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;
		if(number == arr[mid1]) {
			return mid1;
		}
		if(number == arr[mid2]) {
			return mid2;
		}
		if(number < arr[mid1]) {
			return ternary(arr,left,--mid1,number);
		}

		else if(number > arr[mid2]) {
			return ternary(arr,++mid2,right,number);
		}
		else {
			return ternary(arr,mid1++,--mid2,number);
		}
	}
	return -1;
}
