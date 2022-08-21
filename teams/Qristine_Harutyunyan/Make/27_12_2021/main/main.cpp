#include <iostream>

#include "./sum_sub/sub/sub.hpp"
#include "./sum_sub/sum.hpp"
#include "./mult_div/div/div.hpp"
#include "./mult_div/mult.hpp"


int main() {
	int a = 5;
	int b = 7;
	std::cout << "Sum of " << a << " and " << b << " is a " << sum(a, b);
	std::cout << "Diff of " << a << " and " << b << " is a " << sub(a, b);
	std::cout << "Mult of " << a << " and " << b << " is a " << mult(a, b);
	std::cout << "Div of " << a << " and " << b << " is a " << divide(a, b);
	return 0;
}
