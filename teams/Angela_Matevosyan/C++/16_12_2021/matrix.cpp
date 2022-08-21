#include <iostream>
int add(int num1, int num2) {
	return num1 + num2;
}

int sub(int num1, int num2) {
	return num1 - num2;
}

int** newArray(int** arr1, int** arr2, int rows, int cols, int(*operation)(int,int)) {
	int** result = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		result[i] = new int[cols];
	}
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
		result[i][j] = operation(arr1[i][j], arr2[i][j]);
		}
	}
	return result;
}

void printArray(int** array, int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void deleteDynamicArray(int** array, int rows) {
	for (int i = 0; i < rows; ++i) {
		delete[] array[i];
	}
	delete[] array;
}

int main() {
	int rows = 3;
	int cols = 3;
	int** arr1 = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		arr1[i] = new int[cols];
	}

	int** arr2 = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		arr2[i] = new int[cols];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			arr1[i][j] = random() % 90 + 10;
			arr2[i][j] = random() % 90 + 10;
		}
	}

	int** newArr1 = newArray(arr1, arr2, rows, cols, add);
       	int** newArr2 = newArray(arr1, arr2, rows, cols, sub);

	std::cout << "Matrix 1 is: " << std::endl;
	printArray(arr1, rows, cols);

	std::cout << "Matrix 2 is: " << std::endl;
	printArray(arr2, rows, cols);

	std::cout << "The sum of this two matrixes is equal to: " << std::endl;
	printArray(newArr1, rows, cols);

	std::cout << "The subtraction of this two matrixes is equal to: " << std::endl;
	printArray(newArr2, rows, cols);

	deleteDynamicArray(arr1, rows);
	deleteDynamicArray(arr2, rows);
	deleteDynamicArray(newArr1, rows);
	deleteDynamicArray(newArr2, rows);

	return 0;
}
