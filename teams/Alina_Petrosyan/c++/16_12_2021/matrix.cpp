#include <iostream>

int sum(int num1, int num2) {
	return num1 + num2;
}

int sub(int num1, int num2) {
	return num1 - num2;
}

void operation(int * matrix1[], int * matrix2[], int * matrix3[], int (*operation) (int, int)) {
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			matrix3[i][j] = operation(matrix1[i][j], matrix2[i][j]);
		}
	}
}

void printRow(int array[]) {
	for(int i = 0; i < 3; ++i) {
		std::cout << array[i];
		if(array[i] >= 10 || array[i] < 0) {
			std::cout << "  ";
		}
		else {
			std::cout << "   ";
		}
	}
}

void print(int * matrix1[], int * matrix2[], int * matrix3[], char ch, void (*printRow) (int*)) {
	for(int i = 0; i < 3; ++i) {
                printRow(matrix1[i]);
                if(i == 1) {
                        std::cout << ch << "   ";
                }
                else {
                        std::cout << "    ";
                }
                printRow(matrix2[i]);
                if(i == 1) {
                        std::cout << "=   ";
                }
                else {
                        std::cout << "    ";
                }
                printRow(matrix3[i]);
                std::cout << "\n";
        }
}

int main() {
	int ** matrix3 = new int * [3];
	for(int i=0; i < 3; ++i) {
		matrix3[i] = new int [3];
	}
	int ** matrix1 = new int * [3];
	matrix1[0] = new int [3] {1, 2, 3};
	matrix1[1] = new int [3] {4, 5, 6};
	matrix1[2] = new int [3] {7, 8, 9};
	int ** matrix2 = new int * [3];
	matrix2[0] = new int [3] {2, 3, 1};
	matrix2[1] = new int [3] {2, 5, 0};
	matrix2[2] = new int [3] {10, 8, 9};
	operation(matrix1, matrix2, matrix3, sum);
	print(matrix1, matrix2, matrix3, '+', printRow);
	std::cout << "\n";
	operation(matrix1, matrix2, matrix3, sub);
	print(matrix1, matrix2, matrix3, '-', printRow);
	return 0;
}
