#include <iostream>

int operand_or(int x, int y, char sim) {
	std::cout << x << " | " << y << " = " << (x | y) << std::endl;
	return x | y;
}

int operand_and(int x, int y, char sim) {
	std::cout << x << " & " << y << " = " << (x & y) << std::endl;
	return x & y;
}

int operand_xor(int x, int y, char sim) {
	std::cout << x << " ^ " << y << " = " << (x ^ y) << std::endl;
	return x ^ y;
}

int operand_rightshift(int x, int y, char sim) {
	std::cout << x << " >> " << y << " = " << (x >> y) << std::endl;
	return x >> y;
}

int operand_leftshift(int x, int y, char sim) {
	std::cout << x << " << " << y << " = " << (x << y) << std::endl;
	return x << y;
}

void switch_fu(int a, int b, char sign) {
	switch(sign) {
	case '|':
	       	operand_or(a, b, sign);
		break;
	case '&':
		operand_and(a, b, sign);
		break;
	case '^':
		operand_xor(a, b, sign);
		break;	
	case '>':
		operand_rightshift(a ,b, sign);
		break;
	case '<':
		operand_leftshift(a, b, sign);
		break;
	default : std::cout << "Invalid operand!";
	}
}

int main() {
	int a;
	int b;
	char sign;

	std::cout << "Input first operand: ";
	std::cin >> a;

	std::cout << "Input second operand: ";
	std::cin >> b;

	std::cout << "Input operator(Please enter < or > for left and right shift) : ";
	std::cin >> sign;
	switch_fu(a, b, sign);
	return 0;
}
