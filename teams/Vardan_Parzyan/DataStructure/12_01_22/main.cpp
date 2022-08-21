#include <iostream>
#include "LList.hpp"

int main(){
    List list;
    list.pushFront(15);
    list.pushFront(20);
    list.pushBack(60);
    list.pushBack(40);
    list.pushFront(50);
    list.printList();
    list.remove(60);
    list.printList();
    list.pushFront(90);
    list.printList();
    list.insert(1,666);
    list.printList();
    
    
    
    return 0;
}
