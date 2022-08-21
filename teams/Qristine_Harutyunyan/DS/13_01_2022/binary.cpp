#include <iostream>


class Node {
public:	
	int num;
	Node* left;
	Node* right;

	Node(int n) {
		num = n;
		left = NULL;
		right =NULL;
	}
};


class BinarySTree {
	Node* root;
public:
	BinarySTree() {
		this->root = NULL;
	}

	Node* insert(Node* temp, int n){
		if( temp == NULL) {
			temp = new Node(n);
			temp->num = n;
			temp->left = NULL;
			temp->right = NULL;
			} 
			else if (n > temp->num) {
				temp->right = insert(temp->right, n);
			} else if(n < temp->num) {
				temp->left = insert(temp->left, n);
			}
				return temp;
	}

	void insert(int n) {
		root = insert(root, n);
    }
	
	Node* remove(Node* temp, int n) {
		Node* node;
		if(node == NULL){
			return NULL;
		} else if (n < temp->num) {
			temp->left = remove(temp->left, n);
		} else if(n > temp->num) {
			temp->right = remove(temp->right, n);
		} else {
			node = temp;
			if(temp->left == NULL) {
				temp = temp->right;
			} else if (temp->right = NULL){
				temp = temp->left;
			}
			delete node;
		}
		return temp;
	}

	void remove(int n) {
		root = remove(root, n);
		std::cout << std::endl;
	}


	void order(Node* data) {
		if (data == NULL) {
			return;
		}
		order(data->left);
		std::cout << data->num << " ";
		order(data->right);
	}

	void print() {
		if(root == NULL) {
			std::cout << "Tree is empty " << std::endl;
		} else {
			std::cout << "Tree elements  are  " ;
			order(root);
		}
		std::cout << std::endl;
	}
};



int main() {
	BinarySTree b;
	b.insert(10);
	b.print();
	b.insert(20);
	b.insert(8);
	b.insert(5);
	b.insert(9);
	b.insert(15);
	b.insert(25);
	b.print();
	b.remove(9);
	b.print();
	  



    return 0;
}
