#include <iostream>
#include "./binarySearch.hpp"

int main() {
	BinarySearch b;
	b.insert(50);
	b.insert(20);
	b.insert(30);
	b.insert(70);
	b.insert(5);
	b.insert(80);
	b.insert(60);
	
	std::cout << "Root : " << b.getRoot()->data << std::endl;
	b.printOrders();
	b.print();
	b.del(30);
	b.print();

	b.search(5);
	
	return 0;
}

