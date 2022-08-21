#include "Node.cpp"

class List {
public:

    Node* head;
    Node* tail;

List();
List(List& list);
void pushFront(int);
void pushBack(int);
void popBack();
void popFront();
void insert(int,int);
void remove(int);
void printList();
};
