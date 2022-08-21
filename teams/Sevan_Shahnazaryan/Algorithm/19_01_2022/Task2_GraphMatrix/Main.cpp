#include <iostream>
#include "Matrix.hpp"

int main() {
	char input = ' ';
	Matrix::print();
	std::cout << "Enter a vertex you want to analyze: ";
	std::cin >> input;
	Matrix::printVertex(input);
	return 0;
}
