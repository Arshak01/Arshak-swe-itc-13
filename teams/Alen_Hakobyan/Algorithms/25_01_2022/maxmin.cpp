#include<iostream>

void getMaxMin(int* arr, int first, int last, int &min, int& max);

int main() {
	int size = 7;
	int arr[size] = {15,7,8,10,9,6,2};
	int min;
	int max;
	getMaxMin(arr, 0, size - 1, min, max);
	std::cout << "Minimum element of array is: " << min << std::endl;
	std::cout << "Maximum element of array is: " << max << std::endl;

	return 0;
}

void getMaxMin(int* arr, int first, int last, int &min, int &max) {
	if(first == last) {
		min = max = arr[first];
	}
	else {
		int midpoint = (first + last) / 2;
		int leftMin;
		int leftMax;
		int rightMin;
		int rightMax;
		getMaxMin(arr, first, midpoint, leftMin, leftMax);
		getMaxMin(arr, midpoint + 1, last, rightMin, rightMax);
		if (leftMin < rightMin) {
			min = leftMin;
		}
		else {
			min = rightMin;
		}
		if(leftMax > rightMax) {
			max = leftMax;
		}
		else {
			max = rightMax;
		}
	}
}
