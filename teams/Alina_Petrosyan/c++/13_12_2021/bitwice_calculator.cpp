#include <iostream>
namespace custom {
	int OR(int a, int b) {
		return a | b;
	}

	int AND(int a, int b) {
		return a & b;
	}

	int XOR(int a, int b) {
		return a ^ b;
	}

	int leftShift(int a, int b) {
		return a << b;
	}

	int rightShift(int a, int b) {
		return a >> b;
	}
}

int bitwiceCalc(int a, int b, char c) {
	switch (c) {
		case '|': return custom::OR(a, b);
		case '&': return custom::AND(a, b);
		case '^': return custom::XOR(a, b);
		case '<': return custom::leftShift(a, b);
		case '>': return custom::rightShift(a, b);
	}
	return 0;
}

int main() {
	int a, b;
	char c;
	std::cout << "input first operand: ";
	std::cin >> a;
	std::cout << "input second operand: ";
	std::cin >> b;
	std::cout << "input operator: ";
	std::cin >> c;
	std::cout << a << " " << c << " " << b << " = " << bitwiceCalc(a, b, c) << std::endl;
	return 0;
}
