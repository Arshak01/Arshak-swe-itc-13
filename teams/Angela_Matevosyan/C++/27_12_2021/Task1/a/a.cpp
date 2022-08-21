#include <iostream>
#include "../b/bheader.hpp"
#include "../c/cheader.hpp"
#include "../d/dheader.hpp"
#include "../e/esource.hpp"

int main() {
	int n1;
	int n2;
	char c;
	std::cout << "***Calculator***" << std::endl;
	std::cout << "Type like this: number1 -> operation symbol -> number2\n"; 
	std::cin >> n1 >> c >> n2;
	switch(c) {
		case '+' :
			std::cout << n1 + n2;
			break;
		case '-' :
			std::cout << n1 - n2;
			break;
		case '*' :
			std::cout << n1 * n2;
			break;
		case '/' :
			std::cout << n1 / n2;
			break;
	}
	return 0;

}
