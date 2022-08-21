#include <iostream>
#include "./divv/divv.hpp"
#include "./mult/mult.hpp"
#include "./sum/sum.hpp"
#include "./sub/sub.hpp"

int main() {
	int a;
	int b;
	char c;
	std::cout << "***CALCULATOR***\n";
	std::cout << "Type like this:\n
		Number1 -> operation symbol -> number2\n";
	std::cin >> a >> c >> b;
	switch(c) {
		case '+' :
			std::cout << sum(a, b) << std::endl;
			break;
		case '-' :
			std::cout << sub(a, b) << std::endl;
			break;
		case '*' :
			std::cout << mult(a, b) << std::endl;
			break;
		case '/' :
			std::cout << divv(a, b) << std::endl;
			break;
	}
	return 0;
}
