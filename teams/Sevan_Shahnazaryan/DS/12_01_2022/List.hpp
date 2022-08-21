#ifndef LIST
#define LIST
#include "Node.hpp"

class List {
private:
	unsigned int length;
	Node *tail;
	Node *head;

public:
	List();

	List(int length, Node *tail, Node *head);

	List(List& obj);

	Node* getHead() const;
	
	Node* getTail() const;

	void setHead(Node *head);

	void setTail(Node *tail);

	void firstElem(int val);

	void pushFront(int val);

	void pushBack(int val);

	void popBack();

	void popFront();

	void remove(int data);

	void insert(unsigned int position, int data);

	void print();
};

#endif
