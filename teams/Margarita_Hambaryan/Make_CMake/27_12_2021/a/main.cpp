#include <iostream>
#include "./b/sumH.hpp"
#include "./c/subH.hpp"
#include "./c/d/multH.hpp"
#include "./c/d/e/divH.hpp"

float calculator(float num1, float num2, char operation);

int main() {
	float num1;
	float num2;
	char operation;
	std::cout << "Hi. I am calculator and can count sum/subtract/product/division of two float numbers./n";
	std::cout << "Pls, enter the first number: ";
	std::cin >> num1;
	
	std::cout << "Pls, enter the operation you want(+, -, *, /): ";
	std::cin >> operation;

	std::cout << "Pls, enter the second number: ";
	std::cin >> num2;
	
	calculator(num1, num2, operation);
	return 0;
}

float calculator(float num1, float num2, char operation) {
	switch(operation) {
		case '/': {
			return div(num1, num2);
		}
		case '*': {
			return mult(num1, num2);
		}
		case '-': {
			return sub(num1, num2);
		}
		case '+': {
			return sum(num1, num2);
		}
	}
	return 0;
}



/*
int main() {
	float num1 = 51;
	float num2 = 17;
	std::cout << mult(num1, num2) << std::endl;

	return 0;
}


*/
