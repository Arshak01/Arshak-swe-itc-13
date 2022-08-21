#include <iostream>
#include <chrono>
#include "SelectionSort.hpp"

using namespace std::chrono;

int main() {
	const int size = 100; //You can put here your own number
	int *arr = SelSort::randomGen(size);
	std::cout << "\nArray before Selection sort\n" << std::endl;
	SelSort::print(arr, size);

	auto start = high_resolution_clock::now();
	SelSort::sort(arr, size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "\nArray after Selection sort\n" << std::endl;
	SelSort::print(arr, size);
	std::cout << "\nArray sorting done in " << duration.count() << " microseconds" << std::endl;

	delete[] arr;
	arr = NULL;
	return 0;
}
