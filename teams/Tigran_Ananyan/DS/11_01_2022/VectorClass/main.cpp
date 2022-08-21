#include <iostream>
#include "VectorClass.hpp"

int main() {
	Vector v;
	std::cout << "Pushing, Vector = {2, 34, 12}" << std::endl;
	v.push(2);
	v.push(34);
	v.push(12);
	std::cout << "Capacity = " << v.capacity() << std::endl;
	std::cout << "Size = " << v.size() << std::endl;
	v.print();
	std::cout << "Insert value 34 to index 3" << std::endl;
	v.insert(3,34);
	std::cout << "Capcity = " << v.capacity() << std::endl;
	std::cout << "Size = " << v.size() << std::endl;
	v.print();
	std::cout << "Popping" << std::endl;
	v.pop();
	std::cout << "Capacity = " << v.capacity() << std::endl;
	std::cout << "Size = " << v.size() << std::endl;
	v.print();
	std::cout << "v[1] = " << v[1] << std::endl;
	return 0;
}
