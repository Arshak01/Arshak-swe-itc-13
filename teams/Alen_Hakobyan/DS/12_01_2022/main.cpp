#include <iostream>
#include "list.h"

int main() {
	List l;
	l.pushBack(10);
	l.pushBack(20);
	l.pushBack(30);
	l.pushBack(40);
	l.pushBack(50);
	l.pushBack(20);
	l.pushBack(60);
	l.print();
	std::cout << "After push front ";
	l.pushFront(5);
	l.print();
	std::cout << "After pop front and back ";
	l.popFront();
	l.popBack();
	l.print();
	std::cout << "After remove only the first element (20) ";
	l.remove(20);
	l.print();
	std::cout << "After insert index (0) element (100) ";
	l.insert(0,100);
	l.print();
	std::cout << "Copy Constructor "; 

	List l1 = l;
	l1.print();

	return 0;
}
