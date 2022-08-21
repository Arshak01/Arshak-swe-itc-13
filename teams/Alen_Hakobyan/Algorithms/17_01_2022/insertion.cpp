#include <iostream>
#include <chrono>
using namespace std::chrono;

void insertionArr(int* arr, int size);
void print(int* arr, int size);

auto start = high_resolution_clock::now();
int main() {
	int size = 6;
	int arr[size] = {67,8,9,45,74,12};
	print(arr,size);
	std::cout << "Array elements befor insertion sort is : ";
	print(arr,size);
	insertionArr(arr,size);
	std::cout << "Array elements after insertion sort is : ";
	print(arr,size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	print(arr,size);
	std::cout << "Function time is : " << duration.count() << std::endl;

	return 0;
}

void insertionArr(int* arr, int size) {
	int temp = 0;
	for(int i = 1; i < size; ++i) {
		while(arr[i] < arr[i - 1] && i > 0) {
			if(arr[i] < arr[i - 1]) {
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
			i--;
		}
	}
}

void print(int* arr, int size) {
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
