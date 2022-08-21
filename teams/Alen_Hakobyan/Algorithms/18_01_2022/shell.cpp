#include <iostream>
#include <chrono>
using namespace std::chrono;

void shellSort(int* arr, int size);
void print(int* arr, int size);

auto start = high_resolution_clock::now();
int main() {
	int arr[8] = {8,10,5,9,24,3,20,14};
	std::cout << "Array elements befor shell sort : ";
	print(arr,8);
	shellSort(arr,8);
	std::cout << "Array elements after shell sort : ";
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	print(arr,8);
	std::cout << "Function time is : " << duration.count() << std::endl;
	
	return 0;
}

void shellSort(int* arr, int size) {
	int temp = 0;
	int gap = size / 2;
	for(gap; gap > 0; gap /= 2) {
		for(int i = gap; i < size; ++i) {
			int j = i;
			temp = arr[i];
			while(arr[j - gap] > temp && j >= gap) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
	}
}

void print(int* arr, int size) {
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
