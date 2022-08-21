#include <iostream>
#include "Quick.hpp"

int main() {
	const int size = 20;
	int *arr = Quick::randomGen(size);
	std::cout << "\nArray before Quick sort\n" << std::endl;
	Quick::print(arr, size);
	int *sorted = Quick::sort(arr, size);
	std::cout << "\nArray after Quick sort\n" << std::endl;
	Quick::print(sorted, size);
	return 0;
}
