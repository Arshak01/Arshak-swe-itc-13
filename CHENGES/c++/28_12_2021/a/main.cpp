#include <iostream>
#include "./c/sum.hpp"
#include "./c/d/sub.hpp"
#include "./c/d/e/mul.hpp"
#include "./b/divv.hpp"


int main() {
	std::cout << " Main Function " << std::endl;
	std::cout << sum(15, 3) << std::endl;
	std::cout << sub(15, 3) << std::endl;
	std::cout << mul(15, 3) << std::endl;
	std::cout << divv(15, 3) << std::endl;

	return 0;
}
