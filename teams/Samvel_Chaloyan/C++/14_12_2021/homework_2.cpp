#include <iostream>
	
void print(int *arr, int size) {
	std::cout << "Array : ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void asc(int *arr, int size) {
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i+1]) {
				int tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i + 1] = tmp;
			}
		}
	}
	std::cout << "Array with ascending order : ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void desc(int *arr, int size) {
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size - 1; i++) {
			if (arr[i+1] > arr[i]) {
				int tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i + 1] = tmp;
			}
		}
	}
	std::cout << "Array with descending order : ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void rev(int *arr, int size) {
	for (int i = 0; i < size/2; i++) {
		int tmp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i -1] = tmp;
	}
	std::cout << "Reverse array : ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int arr[8] = {10, 50, 30, 20, 60, 80, 70, 40};
	int arr_size = sizeof(arr) / sizeof(*arr);
	print(arr, arr_size);
	rev(arr, arr_size);
	asc(arr, arr_size);
	desc(arr, arr_size);
	return 0;	
}
