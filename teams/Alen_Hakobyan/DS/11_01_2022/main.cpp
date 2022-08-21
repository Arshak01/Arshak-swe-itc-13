#include <iostream>
#include "brackets.h"

int main() {
	std::cout << "Enter even number for size of brackets which you want to check : ";
	int count = 0;
	std::cin >> count;
	while(count % 2 != 0 || count == 0) {
		std::cout << "Wrong number, try again!!!" << std::endl;
		std::cin >> count;
	}
	std::string brackets;
	std::cout << "Enter " << count << " bracktes : ";
	std::cin >> brackets;
	if(checkBrackets(brackets,count)) {
		std::cout << "Correct brackets!!!" << std::endl;
	}
	else {
		std::cout << "Not correct brackets!!!" << std::endl;
	}
	return 0;
}
