#include "./node.hpp"

class BinarySearch {
private:
	Node* root;
	Node* left;
	Node* right;

public:
	BinarySearch();
	~BinarySearch();

	void insert(int);
	void del(int);
	void print();
	void search(int);
	bool empty();
	void inOrder(Node* temp);
	void preOrder(Node* temp);
	void postOrder(Node* temp);
	void printOrders();

	Node* getRoot();
	Node* insertRec(int data, Node* temp);
	Node* searchRec(int data, Node* temp);
	Node* isEmpty(Node* temp);

};
