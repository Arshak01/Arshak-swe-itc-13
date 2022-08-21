#include <iostream>
#include "Matrix.hpp"


const int size = 7;
int matrix[size][size] = {{0, 65, 66, 67, 68, 69, 70},
					{65, 0, 7, 12, 0, 0, 0},
					{66, 0, 0, 2, 9, 0, 0, },
					{67, 0, 0, 0, 0, 10, 0},
					{68, 0, 0, 0, 0, 0, 1},
					{69, 0, 0, 0, 4, 0, 5},
					{70, 0, 0, 0, 0, 0, 0}};


void Matrix::print() {
	std::cout << '{';
	for(int i = 0; i < size; ++i) {
		std::cout << '{';
		for(int j = 0; j < size; ++j) {
			if(i == 0 || j == 0) {
				std::cout << char(matrix[i][j]) << ", ";
			} else {
				std::cout << matrix[i][j] << ", ";
			}
		}
		if(i == size - 1) {
			std::cout << "\b\b" << '}';
		} else {
			std::cout << "\b\b" << '}' << std::endl;
		}
	}
	std::cout << '}' << std::endl;
}

void Matrix::printVertex(char ver) {
	for(int i = 0; i < size; ++i) {
		if(ver == (char)matrix[i][0]) {
			for(int j = 1; j < size; ++j) {
				if(matrix[i][j] > 0) {
					std::cout << (char)matrix[0][j] << ", ";
				}
			}
			std::cout << "\b\b" << ' ' << std::endl;
			return;
		}
	}
	std::cout << "None of existing" << std::endl;
}
