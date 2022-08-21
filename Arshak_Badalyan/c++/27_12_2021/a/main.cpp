#include <iostream>
#include "./c/sum.hpp"
#include "./c/d/sub.hpp"
#include "./c/d/e/mul.hpp"
#include "./b/divv.hpp"

int calculator(float n1, char symbol, float n2);
int main() {
	float n1, n2;
	char symbol;
	std::cout << "Input first number: ";
	std::cin >> n1;
	std::cout << "Input symbole :   + - * /  :  ";
	std::cin >> symbol;
	std::cout << "Input second number: ";
	std::cin >> n2;
	float result =	calculator(n1,symbol,n2);
	std::cout << "result : " << result  << std::endl;
	return 0;
}

int calculator(float n1, char symbol, float n2) {
	switch(symbol) {
		case '+': {
			return sum(n1, n2);
		}
		case '-': {
			return sub(n1, n2);
		}
		case '*': {
			return mul(n1, n2);
		}
		case '/': {
			return divv(n1, n2);
		}
		return 0;
	}
	return 0;
}
