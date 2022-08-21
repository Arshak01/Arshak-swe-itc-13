#include <iostream>

int bwand(int a, int b) {
	return (a & b);
}

int bwor(int a, int b) {
	return (a | b);
}

int bwxor(int a, int b) {
	return (a ^ b);
}

int bwleft(int a, int b) {
	return (a << b);
}

int bwright(int a, int b) {
	return (a >> b);
}

int bitwiceCalc1(int a, int b, char symbol) {
	switch (symbol) {
		case '&': {
			return bwand(a,b);
		}
		case '|': {
			return bwor(a,b);
		}
		case '^': {
			return bwxor(a,b);
		}
		case '>': {
			return bwright(a,b);
		}
		case '<': {
			return bwleft(a,b);
		}
	}
	return 0;
}

int bitwiceCalc2(int a) {
	return (~a);
}

int main() {
	int a,b;
	char symbol;
	std::cout << "Input first operand: ";
	std::cin >> a;
	std::cout << "Input operator like (& | ^ ~ < >)";
	std::cin >> symbol;
	if(symbol == '~') {
		std::cout << symbol << " " << a << " = ";
		std::cout << bitwiceCalc2(a) << std::endl;
	}
	else {
		std::cout << "Input second operand: ";  
		std::cin >> b;
		std::cout << a << " " << symbol << " " << b << " = ";
		std::cout << bitwiceCalc1(a,b,symbol) << std::endl;
	}
	return 0;
}
