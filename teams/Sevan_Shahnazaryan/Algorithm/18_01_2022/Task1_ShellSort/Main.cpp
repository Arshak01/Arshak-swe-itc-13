#include <iostream>
#include <chrono>
#include "ShellSort.hpp"


int main() {
	using namespace std::chrono;
	const int size = 100;
	int *arr = ShellSort::randomGen(size);
	std::cout << "\nArray Before Shell Sort\n" << std::endl;
	ShellSort::print(arr, size);

	auto start = high_resolution_clock::now();
	ShellSort::sort(arr, size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "\nArray After Shell Sort\n" << std::endl;
	ShellSort::print(arr, size);

	std::cout << "Array sorting done in " << duration.count() << " microseconds" << std::endl;
	return 0;
}
