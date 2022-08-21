#include <iostream>

void init(int**, int);
void destroy(int**, int);
void destroy(float**, int);
void print(int**, int);

int main() {
	const int LENGTH = 3;
	srand(time(NULL));

	int** arr1 = new int* [LENGTH];
	int** arr2 = new int* [LENGTH];
	int** sum = new int* [LENGTH];
	int** sub = new int* [LENGTH];

	float** arrF1 = new float* [LENGTH];
 	float** arrF2 = new float* [LENGTH];
 	float** sumF = new float* [LENGTH];
 	float** subF = new float* [LENGTH];
	
	void* ptr1 = &arr1;
	void* ptr2 = &arr2;
	void* ptrSum = &sum;
	void* ptrSub = &sub;

	init(arr1, LENGTH);
	init(arr2, LENGTH);
	init(sum, LENGTH);
	init(sub, LENGTH);

	void* ptr1 = &arrF1;
	void* ptr2 = &arrF2;
	void* ptrSum = &sumF;
	void* ptrSub = &subF;
	
	init(arrF1, LENGTH);
	init(arrF2, LENGTH);
	init(sumF, LENGTH);
	init(subF, LENGTH);


	
	for (int i = 0; i < LENGTH; ++i) {
		for (int j = 0; j < LENGTH; ++j) {
			sum[i][j] = arr1[i][j] + arr2[i][j];
			sub[i][j] = arr1[i][j] - arr2[i][j];
			sumF[i][j] = arr1[i][j] + arr2[i][j];
			subF[i][j] = arr1[i][j] - arr2[i][j];

		}
	}

	print(*(int *)ptr1, LENGTH);
	print(*(int *)ptr2, LENGTH);
	std::cout <<  "=== sum ===" << std::endl;
	std::cout << std::endl;

	print(*(int *)ptrSum, LENGTH);
	std::cout <<  "=== sub ===" << std::endl;
	std::cout << std::endl;

	print(*(int *)ptrSub, LENGTH);

	std::cout << std::endl;					

	print(*(float *)ptr1, LENGTH);
	print(*(float *)ptr2, LENGTH);
	std::cout <<  "=== sumF ===" << std::endl;
	std::cout << std::endl;

	print(*(float *)ptrSum, LENGTH);
	std::cout <<  "=== subF ===" << std::endl;
	std::cout << std::endl;

	print(*(float *)ptrSub, LENGTH);

	destroy(arrF1, LENGTH);
	destroy(arrF2, LENGTH);
	destroy(sumF, LENGTH);
	destroy(subF, LENGTH);


	destroy(arr1, LENGTH);
	destroy(arr2, LENGTH);
	destroy(sum, LENGTH);
	destroy(sub, LENGTH);

	return 0;
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
void init(float** arr, int length) {
	for(int i = 0; i < length; ++i) {
		arr[i] = new float[length];
	}
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			arr[i][j] = rand()/float(RAND_MAX)*24.f+1.f;
		}
	}
}

void destroy(int** arr, int length) {
	for (int i = 0; i < length; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

void destroy(float** arr, int length) {
	for (int i = 0; i < length; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

void print(void* arr, int length) {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
