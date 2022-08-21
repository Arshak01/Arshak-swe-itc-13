#include <iostream>

int** createMatrix(int x, int y) {
	int** matrix = new int*[x];
	for (int i = 0; i < x; i++) {
		matrix[i] = new int[y];	
	}
	return matrix;
}

void initMatrix(int** matrix, int x, int y, int shift) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			matrix[i][j] = i + j + shift;
		}
	}
}

void printMatrix(int** matrix, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int** matrixMath(int** m1, int** m2, int x, int y, int (*math)(int, int) ) {
	int** m3 = createMatrix(x, y);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			m3[i][j] = math(m1[i][j], m2[i][j]);
		}
	}
	return m3;
} 

int sum(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int main() {

	int** matrix_first = createMatrix(3, 3);
	int** matrix_second = createMatrix(3, 3);
	initMatrix(matrix_first, 3, 3, 4);
	initMatrix(matrix_second, 3, 3, 2);
	std::cout << "First Matrix:\n";
	printMatrix(matrix_first, 3, 3);
	std::cout << "Second Matrix:\n";
	printMatrix(matrix_second, 3, 3);
	std::cout << "Plus\n";
	int** sum1 = matrixMath(matrix_first, matrix_second, 3, 3, sum);
	printMatrix(sum1, 3, 3);
	std::cout << "Minus\n";
	int** sub1 = matrixMath(matrix_first, matrix_second, 3, 3, sub);
	printMatrix(sub1, 3, 3);

	for (int i = 0; i < 3; ++i) {
		delete[] matrix_first[i], matrix_second[i], sum1[i], sub1[i];
	}
	delete[] matrix_first, matrix_second, sum1, sub1;
	return 0;
}
