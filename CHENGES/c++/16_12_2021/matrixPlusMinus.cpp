#include <iostream>

void display(int** arr, int row, int col) {
	std::cout << "--------" << std::endl;
	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col; ++j) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void creatMatrix(int** arr, int row, int col) {
	for(int i = 0; i < row; ++i) {
		arr[i] = new int[col];
	}
}

int fillArr(int** arr, int row, int col) {
	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col; ++j) {
			arr[i][j] = random() % 50;
		}
	}
	
	return 0;
}

int plus(int n1, int n2) {
	return n1 + n2;
}

int minus(int n1, int n2) {
	return n1 - n2;
}

int mathFunc(int row, int col, int** result, int** first, int** second,int(*check)(int,int)) {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				result[i][j] += check(first[i][j],second[i][j]);
			}
		}
    	return 0;
}

void deleteMatrix(int** matrix, int row, int col) {
	for (int i = 0; i < row; ++i) {
		delete matrix [i];
	}
	delete[] matrix;
}

void choose(char ch,int** first, int** second, int** result, int row, int col) {
	if(ch == '+') {
		mathFunc(row, col, result, first, second, plus); 
	}else if(ch == '-') {
		mathFunc(row, col, result, first, second, minus); 
	}else {
		std::cout << "Input only + or - " << std::endl;
		std::cin >> ch;
		choose(ch, first, second, result, row, col);
	}
}

int main() {
	char ch;
	int row;
	int col;

	std::cout << "Enter the number of row: ";
	std::cin >> row;
	std::cout << "Enter the number of column: ";
	std::cin >> col;
	std::cout << "Enter math symbole '+' or '-': ";
	std::cin >> ch;
	
	int** first  = new int*[row,col];
	int** second = new int*[row,col];
	int** result = new int*[row,col];
	
	creatMatrix(first, row, col);
	creatMatrix(second,row, col);
	creatMatrix(result,row, col);

	fillArr(first, row, col);
	fillArr(second, row, col);
	choose(ch, first, second, result, row, col);
	
	std::cout << "\nfirst" << std::endl;
	display(first, row, col);
	std::cout << "\nsecond" << std::endl;
	display(second, row, col);
	std::cout << "\nresult" << std::endl;
	display(result, row, col);
	
	deleteMatrix(first, row, col);
	deleteMatrix(second, row, col);
	deleteMatrix(result, row, col);
	
	return 0;	
}
