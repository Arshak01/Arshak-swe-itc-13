#include <iostream>
#include "DLList.hpp"

int main() {
    DLList dll;
    dll.remove(234);
    dll.popBack();
    dll.popFront();
    dll.insert(4, 5);
    dll.print();
    dll.pushFront(25);
    dll.pushFront(5);
    dll.pushFront(144);
    dll.insert(1, 10);
    dll.print();
    dll.pushFront(56);
    dll.pushFront(45);
    dll.pushFront(16);
    dll.pushFront(89);
    dll.print();
    dll.pushBack(4);
    dll.pushBack(71);
    dll.pushBack(1);
    dll.print();
    dll.popBack();
    dll.print();
    dll.popFront();
    dll.print();
    dll.remove(144);
    dll.remove(56);
    dll.print();
    std::cout << std::endl;
    DLList dll1 = dll;
    dll1.print();
    dll1.pushBack(23);
    dll1.print();
    dll.print();
    std::cout << "Destructing ..." << std::endl;
    return 0;
}
