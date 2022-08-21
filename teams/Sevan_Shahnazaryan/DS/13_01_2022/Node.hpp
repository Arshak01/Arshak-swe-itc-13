#ifndef NODE
#define NODE

class Node {
private:
	int num;
	Node *left;
	Node *right;

public:
	Node();

	Node(int num, Node *left, Node *right);	

	int getNum() const;

	Node* getLeft() const;

	Node* getRight() const;

	void setNum(int num);

	void setLeft(Node *left);

	void setRight(Node *right);	
};

#endif
