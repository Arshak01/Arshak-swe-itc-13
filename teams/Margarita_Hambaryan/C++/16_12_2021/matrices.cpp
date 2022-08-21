#include <iostream>
#define LEN 3

int subtract(int num1, int num2) {
	return num1 - num2;
}

int sum(int num1, int num2) {
	return num1 + num2;
}

int **resultArray(int **array1, int **array2, int countOfRow, int countOfCol, int (*action)(int, int)) {
	//creating the result in heap
	int **result = new int*[countOfRow];
	for (int row = 0; row < countOfRow; ++row) {
		result[row] = new int[countOfCol];
	}
	
	//filling the result
	for (int row = 0; row < countOfRow; ++row) {
		for (int col = 0; col < countOfCol; ++col) {
			result[row][col] = action(array1[row][col], array2[row][col]);
		}
	}
	return result;
}


int main() {
	int countOfRow = 3;
	int countOfCol = 3;
	const int nestedArrL = 3;
	
	//creating the array1 in heap memory	
	int **array1 = new int*[LEN];
	for (int i = 0; i < LEN; ++i) {
		array1[i] = new int[nestedArrL];
	}

	//creating the array2 in heap memory		
	int **array2 = new int*[LEN];
	for (int i = 0; i < LEN; ++i) {
		array2[i] = new int[nestedArrL];
	}

	//filling the arrays
	for (int row = 0; row < countOfRow; ++row) {
		for (int col = 0; col < countOfCol; ++col) {
			array1[row][col] = random() % 5 + 4;
			array2[row][col] = random() % 5 + 4;
		}
	}
	

	int **resultOfSum =  resultArray(array1, array2, countOfRow, countOfCol, sum);
	int **resultOfSubtract = resultArray(array1, array2, countOfRow, countOfCol, subtract);	


	//printing the sum of matrices
	for (int i = 0; i < countOfRow; ++i) {
		if ((i == (i % 2) + (i / 2)) && (i != 0)) {
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << array1[i][j] << " ";
			}
			std::cout << "   +   ";
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << array2[i][j] << " ";
			}
			std::cout << "   =   ";
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << resultOfSum[i][j] << " ";
			}
			std::cout << "\n";
		}else {
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << array1[i][j] << " ";
			}
				std::cout << "       ";
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << array2[i][j] << " ";
			}
				std::cout << "       ";
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << resultOfSum[i][j] << " ";
			}		
			std::cout << "\n";
		}
	}

	std::cout << "\n\n";
	//printing the subtract of matrices
	for (int i = 0; i < countOfRow; ++i) {
		if ((i == (i % 2) + (i / 2)) && (i != 0)) {
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << array1[i][j] << " ";
			}
			std::cout << "   -   ";
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << array2[i][j] << " ";
			}
			std::cout << "   =   ";
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << resultOfSubtract[i][j] << " ";
			}
			std::cout << "\n";
		}else {
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << array1[i][j] << " ";
			}
				std::cout << "       ";
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << array2[i][j] << " ";
			}
				std::cout << "       ";
			for (int j = 0; j < countOfCol; ++j) {
				std::cout << resultOfSubtract[i][j] << " ";
			}		
			std::cout << "\n";
		}
	}


	//deleting array1 from the heap
	for (int i = 0; i < LEN; ++i) {
		delete[] array1[i];
	}
	delete[] array1;

	//deleting array2 from the heap
	for (int i = 0; i < LEN; ++i) {
		delete[] array2[i];
	}
	delete[] array2;

	//deleting the results from the heap
	for (int i = 0; i < LEN; ++i) {
		delete[] resultOfSubtract[i];
		delete[] resultOfSum[i];
	}
	delete[] resultOfSum;
	delete[] resultOfSubtract;
	

	return 0;
}
