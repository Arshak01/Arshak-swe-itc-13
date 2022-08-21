#include <iostream>
#include "Node.hpp"
#include "List.hpp"
#include "Iterator.hpp"

int main() {
	List list;
	list.pushFront(3);
	list.pushFront(4);
	std::cout << "After pushFronting 3 and 4" << std::endl;
	list.print();
	list.pushBack(2);
	list.pushBack(1);
	std::cout << "After pushBacking 2 and 1" << std::endl;
	list.print();
	List list2 = list;
    std::cout << "After using copy constructor" << std::endl;
    list2.print();
	list.popBack();
	std::cout << "After popBack" << std::endl;
	list.print();
	list.popFront();
	std::cout << "After popFront" << std::endl;
	list.print();
	list.insert(1, 11);
	std::cout << "After insert(1, 11)" << std::endl;
	list.print();
	list.remove(11);
	std::cout << "After remove(11)" << std::endl;
	list.print();
}
