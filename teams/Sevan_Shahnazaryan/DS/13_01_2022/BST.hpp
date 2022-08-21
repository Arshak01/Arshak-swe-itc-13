#ifndef SearchT
#define SearchT
#include "Node.hpp"

class BST {
private:
	Node *root;
	int level; //To count the height for print
	char **tree;

	Node* search(int data, Node *ptr, int lvl = 0);

	void printCL(Node *ptr, int lvl);

public:
	BST();

	Node* getRoot() const;

	void setRoot(Node *root);

	int getLevel() const;

	void setLevel(int level);

	void insert(int data);

//	void remove(int data, Node *ptr = NULL);

	void print();

};
#endif
