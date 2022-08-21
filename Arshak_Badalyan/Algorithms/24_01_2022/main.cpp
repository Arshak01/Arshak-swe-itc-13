#include <iostream>
#include "./combinition.hpp"

int main() {
	int n, m;
	std::cout << "Entry number : ";
	std::cin >> n;
	std::cout << "Entry power : ";
	std::cin >> m;

	printCombs(n, m);

	return 0;

}
