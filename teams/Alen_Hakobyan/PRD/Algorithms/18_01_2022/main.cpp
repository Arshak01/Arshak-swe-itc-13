#include <iostream>
#include "quick.h"
#include <chrono>
using namespace std::chrono;

auto start = high_resolution_clock::now();
int main() {
	/// Create object of Quick Class
	Quick quick;
	/// quick obj 0
	quick.pushNext(25);
	/// quick obj 1
	quick.pushNext(5);
	/// quick obj 2
	quick.pushNext(15);
	/// quick obj 3
	quick.pushNext(3);
	/// quick obj 4
	quick.pushNext(8);
	std::cout << "List elements befor quick sort : ";
	/// printQuick funtion to print list befor sort
	quick.printQuick();
	/// sort functuion to sort list
	quick.sort(quick.head,quick.lastNode());
	std::cout << "List elements after quick sort : ";
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	/// printQuick function after sort
	quick.printQuick();
	std::cout << "Function time is : " << duration.count() << std::endl;

	return 0;
}
