#ifndef BINARY_TREE
#define BINARY_TREE

class Node {
public:
	unsigned int data;
	Node* left;	
	Node* right;
	Node(int data);	
};

class BinaryTree {
private:
	Node* root;
public:
	BinaryTree();
	~BinaryTree();
	bool isEmpty();
	Node* insert(int data, Node* temp);
	Node* remove(int data, Node* temp);
	Node* makeEmpty(Node* temp);
	void insert(int data);
	void order(Node* temp);
	void deorder(Node* temp);
	void remove(int data);
	void print();
};

#endif
