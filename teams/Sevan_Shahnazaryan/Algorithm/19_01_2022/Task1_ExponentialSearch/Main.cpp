#include <iostream>
#include "Expo.hpp"

int main() {
	int size = 15;
	int elem = 33;
	int *arr = Expo::arrGen(size);
	Expo::print(arr, size);
	std::cout << "Searching " << elem << " in array..." << std::endl;
	std::cout << Expo::search(arr, size, elem) << std::endl;
	return 0;
}
