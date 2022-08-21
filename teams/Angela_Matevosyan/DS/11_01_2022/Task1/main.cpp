#include <iostream>
#include "vector.hpp"

int main() {
	Vector v;
	v.print();
	Vector v1(3, 2);
	v1.print();

	std::cout << "Vector after push(4):\n";
	v1.push(4);
	v1.print();

	std::cout << "Vector after pop method:\n";
	v1.pop();
	v1.print();
	
	std::cout << "Vector after insert 8 value at 1 index:\n";
	v1.insert(1, 8);
	v1.print();

	std::cout << "The number of elements in the vector:\n";
	std::cout << v1.size() << std::endl;

	std::cout << "The size of the storage space currently allocated for the vector:\n";
	std::cout << v1.getCapacity() << std::endl;

	std::cout << "The value at position 2:\n";
	std::cout << v1[2] << std::endl;

	return 0;
}
