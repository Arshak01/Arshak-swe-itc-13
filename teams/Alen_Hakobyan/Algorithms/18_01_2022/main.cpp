#include <iostream>
#include "quick.h"
#include <chrono>
using namespace std::chrono;

auto start = high_resolution_clock::now();
int main() {
	Quick quick;
	quick.pushNext(25);
	quick.pushNext(5);
	quick.pushNext(15);
	quick.pushNext(3);
	quick.pushNext(8);
	std::cout << "List elements befor quick sort : ";
	quick.printQuick();
	quick.sort(quick.head,quick.lastNode());
	std::cout << "List elements after quick sort : ";
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	quick.printQuick();
	std::cout << "Function time is : " << duration.count() << std::endl;

	return 0;
}
