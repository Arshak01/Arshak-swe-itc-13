#include "Node.hpp"

struct DoubleLinkedList {
    int size = 0;
    Node* head;
    Node* tail;

    DoubleLinkedList();

    DoubleLinkedList(const DoubleLinkedList& d);

    ~DoubleLinkedList();

    void pushBack(int);

    void pushFront(int);

    void popBack();

    void popFront();

    void insert(int, int);

    void remove(int);

    void print();
};