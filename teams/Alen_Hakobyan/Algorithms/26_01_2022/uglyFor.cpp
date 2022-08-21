#include <iostream>

int uglyLoop(int index, int* arr);
void print(int* arr, int size);

int main() {
	int index;
	std::cout << "Input index of Ugly number : ";
	std::cin >> index;
	int arr[index];
	std::cout << "Ugly number is : " << uglyLoop(index,arr) << std::endl;
	std::cout << "Array of Ugly number is : ";
	print(arr,index);
}

void print(int* arr, int size){
	for(int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int uglyLoop(int index, int* arr) {
	int index2 = 0;
	int index3 = 0;
	int index5 = 0;
	int nextI2 = 2;
	int nextI3 = 3;
	int nextI5 = 5;
	int nextUgly = 1;
	arr[0] = 1;
	for(int i = 1; i < index; ++i) {
		if(nextI2 < nextI3 && nextI2 < nextI5) {
			nextUgly = nextI2;
		}
		else if(nextI3 < nextI5) {
			nextUgly = nextI3;
		}
		else {
			nextUgly = nextI5;
		}
		arr[i] = nextUgly;
		if (nextUgly == nextI2) {
			++index2;
			nextI2 = arr[index2] * 2;
		}
		if (nextUgly == nextI3) {
			++index3;
			nextI3 = arr[index3] * 3;
		}
		if (nextUgly == nextI5) {
			++index5;
			nextI5 = arr[index5] * 5;
		}
	}
	return nextUgly;
}
