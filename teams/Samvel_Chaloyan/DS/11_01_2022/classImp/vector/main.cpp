#include <iostream>
#include "vectorClass/classVector.h"

int main() {
	Vector num;
	num.push(1);
	num.push(2);
	num.push(3);
	num.push(4);
	std::cout << "The elements of the Vector: ";
	num.printVector();
	std::cout << "The number of elements: ";
	std::cout << num.currentSize() << std::endl;
	num.pop();
	std::cout << "The number of elements after deleted last one: ";
	std::cout << num.currentSize() << std::endl;

	std::cout << "Enter a number to print the element: ";
	int n;
	std::cin >> n;
	std::cout << "The " << n << "th element: ";
	std::cout << num[n - 1] << std::endl;
	return 0;
}
