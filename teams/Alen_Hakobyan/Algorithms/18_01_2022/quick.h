#ifndef QUICK_H
#define QUICK_H

class Node {
public:
	int data;
	Node* next;
	Node(int value);
};

class Quick {
public:
	Node* head;
	Node* tail;
	Quick();
	~Quick();
	void pushNext(int data);
	Node* lastNode();
	Node* position(Node* first, Node* last);
	void sort(Node* first, Node* last);
	void printQuick();
};

#endif
