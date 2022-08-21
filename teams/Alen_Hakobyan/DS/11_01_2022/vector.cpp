#include <iostream>
#include "vector.h"

int main() {
	Vector v;
	v.push(10);
	v.push(20);
	v.push(30);
	std::cout << "Vector size : " << v.size() << std::endl;
	std::cout << "Vector count : " << v.getN() << std::endl;
	std::cout << "Vector elements : ";
	v.print();
	v.insert(40, 1);
	std::cout << "After updating 1st index." << std::endl;
	std::cout << "Vector elements : ";
	v.print();
	std::cout << "Push 50, 60, 70." << std::endl;
	v.push(50);
	v.push(60);
	v.push(70);
	std::cout << "Vector elements : ";
	v.print();
	std::cout << "Vector size : " << v.size() << std::endl;
	std::cout << "Vector count : " << v.getN() << std::endl;
	std::cout << "Element at 1st index : ";
	v.setIndex(1);
	v.pop();
	std::cout << "After deleting last element." << std::endl;
	std::cout << "Vector size : " << v.size() << std::endl;
	std::cout << "Vector count : " << v.getN() << std::endl;
	std::cout << "Vector elements : ";
	v.print();
 
    return 0;
}
