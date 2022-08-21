#ifndef LIST_H
#define LIST_H

class Node {
public:
	int data;
	Node* prev;
	Node* next;
	Node(int num);
};

class List {
private:
	Node* front;
	Node* end;
public:
	List();
	List(List& list);
	~List();
	bool isEmpty();
	void pushBack(int data);
	void pushFront(int data);
	void popBack();
	void popFront();
	void insert(int index, int data);
	void remove(int data);
	void print();
};

#endif
