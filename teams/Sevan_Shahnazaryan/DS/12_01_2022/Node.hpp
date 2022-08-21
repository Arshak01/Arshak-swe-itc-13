#ifndef NODE
#define NODE

class Node {
private:
	int num;
	Node* next;
	Node* prev;

public:
	Node();

	Node(int num, Node *next, Node *prev);

	int getNum() const;

	Node* getNext() const;

	Node* getPrev() const;

	void setNum(int num);

	void setNext(Node *next);

	void setPrev(Node *prev);
};
#endif
