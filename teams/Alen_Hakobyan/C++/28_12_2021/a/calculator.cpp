#include <iostream>
#include "./b/sum.hpp"
#include "./c/sub.hpp"
#include "./c/d/mult.hpp"
#include "./c/d/e/divide.hpp"

int main() {
	int numb1, numb2;
	char symbol;
	std::cout << "Input first number: ";
	std::cin >> numb1;
	std::cout << "Input one of + - * / symbols: ";
	std::cin >> symbol;
	std::cout << "Input second number: ";
	std::cin >> numb2;
	if(symbol == '/' && numb2 == 0) {
		std::cout << "For divide the second number cant be 0: try again: ";
		std::cin >> numb2;
	}
	switch(symbol) {
		case '+': {
			std::cout << sum(numb1,numb2) << std::endl;
			break;
		}
		case '-': {
			std::cout << sub(numb1,numb2) << std::endl;
			break;
		}
		case '*': {
			std::cout << mult(numb1,numb2) << std::endl;
			break;
		}
		case '/': {
			std::cout << divide(numb1,numb2) << std::endl;
			break;
		}
	}

	return 0;
}	
