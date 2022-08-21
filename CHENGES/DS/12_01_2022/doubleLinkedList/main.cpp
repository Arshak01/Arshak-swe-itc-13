#include <iostream>
#include "./DLinkedList.hpp"

int main() {
    DLinkedList dl;
    dl.pushFront(1);
    dl.pushFront(2);
    dl.pushFront(3);
    dl.pushBack(4);
    dl.pushBack(5);
    dl.pushBack(6);

   	dl.print();
    dl.popFront();
    dl.print();
    dl.popBack();
    dl.print();
    dl.insert(2,777);
    dl.insertByElement(4,99);
    dl.print();
    dl.insert(10,888);
    dl.print();
    dl.remove(20);
    dl.print();
    dl.remove(2);
    dl.print();
    std::cout << "Head : " << dl.getHead() << std::endl;
    std::cout << "Tail : " << dl.getTail() << std::endl;
    std::cout << "Size : " << dl.getSize() << std::endl;

    return 0;
}
