#include <iostream>
#include "./vector.hpp"


int main() {
	Vector v(2,0);
	v.push(1);
	v.push(2);
	v.push(3);
	v.push(4);
	v.push(5);
	v.print();
	v.push(6);
	v.print();
	v.pop();
	v.print();
	v.deleteAtIndex(2);
	v.print();
	v.insert(2,8);
	v.print();

	std::cout << "Operator [] are : " ;
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Size : " << v.size() << std::endl;
	std::cout << "Capacity : " << v.capacity() << std::endl;
	std::cout << "Empty : " << v.empty() << std::endl;	

	return 0;
}
