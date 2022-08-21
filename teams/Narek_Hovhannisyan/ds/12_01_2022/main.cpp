#include <iostream>
#include "doubleLinkedList.hpp"

int main() {
    DoubleLinkedList dl;
    dl.remove(100);
    dl.popBack();
    dl.popFront();
    dl.insert(5, 12);
    dl.pushFront(10);
    dl.pushFront(10);
    dl.pushFront(71);
    dl.insert(1, 12);
    dl.print();
    dl.pushFront(10);
    dl.pushFront(27);
    dl.pushFront(71);
    dl.print();
    dl.pushBack(7);
    dl.pushBack(5);
    dl.pushBack(1);
    dl.print();
    dl.popBack();
    dl.print();
    dl.popFront();
    dl.print();
    dl.insert(2, 21);
    dl.print();
    dl.remove(1);
    dl.remove(10);
    dl.print();
    std::cout << std::endl;

    DoubleLinkedList dl1 = dl;
    dl1.print();
    dl1.pushBack(155);
    dl1.print();
    dl.print();
    std::cout << "before destructing, this log's purpose is to show destructor working process" << std::endl;

    return 0;
}
