#include "./Node.hpp"

class DLinkedList {
private:
	Node* head;
    Node* tail;
    int size;

public:

    DLinkedList();

    DLinkedList(const DLinkedList& linkedlist);

    void pushBack(int data);

    void pushFront(int data);

    void popBack();

    void popFront();

    void insert(int position, int data);
    
	void insertByElement(int element, int data);

    void remove(int data);

    void print();

    int getHead();

    int getTail();

    int getSize();

    ~DLinkedList();
};
