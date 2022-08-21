#include <iostream>
#include "prod/prod.hpp"
#include "prod/sum/sum.hpp"
#include "div/sub/sub.hpp"
#include "div/divi.hpp"


int main() {
	int num1 = 5;
	int num2 = 6;
	std::cout << num1 << " + " << num2 << " = "
		<< sum(num1, num2) << std::endl;

	std::cout << num1 << " * " << num2 << " = "
		<< prod(num1, num2) << std::endl;

	std::cout << num1 << " / " << num2 << " = "
		<< divi(num1, num2) << std::endl;

	std::cout << num1 << " - " << num2 << " = "
		<< sub(num1, num2) << std::endl;
	return 0;
}
