#include <iostream>
#include <cassert>
#include "Vector.hpp"

int main() {
	Vector vec;
	std::cout << "***Pushing 1,2,4 to Vector***" << std::endl;
	vec.push(1);
	vec.push(2);
	vec.push(4);
	std::cout << "Capacity = " << vec.capacity() << std::endl;
	std::cout << "Size = " << vec.size() << std::endl;
	vec.print();
	std::cout << "***Inserting number 3 to 2nd index***" << std::endl;
	vec.insert(2,3);
	std::cout << "Capcity = " << vec.capacity() << std::endl;
	std::cout << "Size = " << vec.size() << std::endl;
	vec.print();
	std::cout << "***Popping out***" << std::endl;
	vec.pop();
	std::cout << "Capacity = " << vec.capacity() << std::endl;
	std::cout << "Size = " << vec.size() << std::endl;
	vec.print();
	std::cout << "vec[1] = " << vec[1] << std::endl;
	return 0;
}
