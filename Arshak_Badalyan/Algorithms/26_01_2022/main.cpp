#include <iostream>
#include "./BigOTime/bigOTime.hpp"

int main() {
	int num;
	std::cout << "Enter number : ";
	std::cin >> num;
	std::cout << std::endl;
	
	countTime(num);

	return 0;
}
