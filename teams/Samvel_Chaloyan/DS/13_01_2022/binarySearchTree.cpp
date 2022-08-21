#include <iostream>

class Node {
	public:
		Node* left;
		Node* right;
		int data;
		Node();
		Node(int);
};

Node::Node() {
	this -> left = NULL;
	this -> right = NULL;

}

Node::Node(int data) {
	this -> left = NULL;
	this -> right = NULL;
	this -> data = data;

}

class BinarySearchTree {
	private:
		Node* root;
	public:
		BinarySearchTree();
		Node* getRoot();
		void insert(int);
		void deleteElement(int);
		void print(Node*);
};

Node* BinarySearchTree::getRoot() {
	return this -> root;
}

BinarySearchTree::BinarySearchTree() {
	this -> root = NULL;
}

void traversal (Node* root, Node* node) {
	Node* tmp = root;
	while (tmp -> left != NULL && tmp -> right != NULL) {
		if (tmp -> data < node -> data) {
			tmp = tmp -> right;
		} else if (tmp -> data > node -> data) {
			tmp = tmp -> left;
		} else {
			std::cout << "The data already exist." << std::endl;
		}
	}

	if (tmp -> data < node -> data) {
		tmp -> right = node;
	} else if (tmp -> data > node -> data) {
		tmp -> left = node;
	} else {
		std::cout << "The data already exist." << std::endl;
	}
}

void BinarySearchTree::insert(int data) {
	Node* node = new Node(data);
	if (this -> root == NULL) {
		this -> root = node;
	} else {
		traversal(this -> root, node);
	}
}

void BinarySearchTree::deleteElement(int data) {
	
}

void printByLevel(Node* root, int level) {
	if (root == NULL) {
		return;
	}
	
	if (level == 1) {
		std::cout << root -> data << " ";
	} else if (level > 1) {
		printByLevel(root -> left, level - 1);
	      	printByLevel(root -> right, level - 1);	
	}

}

int height(Node* root) {
	if (root == NULL) {
		return 0;
	} else {
		int heightRight = height(root -> right);
		int heightLeft = height(root -> left);

		if (heightLeft > heightRight) {
			return (heightLeft + 1);
		} else {
			return (heightRight + 1);
		}
	} 
}

void printAllLevels(Node* root) {
	for (int i = 0; i <= height(root); ++i) {
		printByLevel(root, i);
		std::cout << std::endl;
	}
}

void BinarySearchTree::print(Node* root) {
	printAllLevels(root);
}

int main() {
	BinarySearchTree* searchTree = new BinarySearchTree();
	searchTree -> insert(8);
	searchTree -> insert(5);
	searchTree -> insert(10);
	searchTree -> insert(4);
	searchTree -> insert(6);
	searchTree -> insert(7);
	searchTree -> print(searchTree -> getRoot());
	return 0;
}
