#ifndef BIN_SEARCH_TREE
#define BIN_SEARCH_TREE

class Node {
public:
	unsigned int data;
	Node* left;
	Node* right;
	Node(int data);
};

class BinSearchTree {
private:
	Node* root;
public:
	BinSearchTree();
	~BinSearchTree();
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
