#include <iostream>

void init(int**, int);
void destroy(int**, int);
void print(int**, int);
int func1(int,int);
int func2(int, int);
int** res(int** arr1, int** arr2, int length, int operation(int,int));

int main() {

	const int LENGTH = 3;
	srand(time(NULL));

	int** arr1 = new int* [LENGTH];
	int** arr2 = new int* [LENGTH];
	int** sum = new int* [LENGTH];
	int** sub = new int* [LENGTH];

	init(arr1, LENGTH);
	init(arr2, LENGTH);
	init(sum, LENGTH);
	init(sub, LENGTH);
	sum = res(arr1,arr2,LENGTH,&func1);
	sub = res(arr1,arr2,LENGTH,&func2);

	print(arr1, LENGTH);
	print(arr2, LENGTH);
	std::cout <<  "=== sum ===" << std::endl;
	std::cout << std::endl;

	print(sum, LENGTH);
	std::cout <<  "=== sub ===" << std::endl;
	std::cout << std::endl;

	print(sub, LENGTH);

	destroy(arr1, LENGTH);
	destroy(arr2, LENGTH);
	destroy(sum, LENGTH);
	destroy(sub, LENGTH);

	return 0;
}

int func1(int num1, int num2) {
	return num1 + num2;
}

int func2(int num1, int num2) {
	return num1 - num2;
}

int** res(int** arr1, int** arr2, int length, int(*operation)(int,int)) {
	int** result = new int*[length];
	for(int i = 0; i < length; ++i) {
		result[i] = new int[length];
		for(int j = 0; j < length; ++j) {
			result[i][j] = operation(arr1[i][j],arr2[i][j]);
		}
	}
	return result;
}

void init(int** arr, int length) {
	for(int i = 0; i < length; ++i) {
		arr[i] = new int[length];
	}
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			arr[i][j] = rand() % 10;
		}
	}
}

void destroy(int** arr, int length) {
	for (int i = 0; i < length; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

void print(int** arr, int length) {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
