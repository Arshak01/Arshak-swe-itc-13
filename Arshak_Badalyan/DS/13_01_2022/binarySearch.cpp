#include <iostream>
#include "binarySearch.hpp"


BinarySearch::BinarySearch() {
	this->root = NULL;
	this->left = NULL;
	this->right = NULL;
}

BinarySearch::~BinarySearch() {
	root = isEmpty(root);
}

void BinarySearch::del(int d) {
	bool found = false;
	if (empty()) {
		std::cout << " This Tree is empty! " << std::endl;
		return;
	}
	Node *curr;
	Node *parent;
	curr = this->root;
	while (curr != NULL) {
		if (curr->data == d) {
			found = true;
			break;
		} else {
		parent = curr;
			if (d > curr->data){
				curr = curr->right;
			} else {
				curr = curr->left;
			}
		}
	}
	if (!found) {
		std::cout << " Data not found! " << std::endl;
		return;
	}

	if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL)) {
		if (curr->left == NULL && curr->right != NULL) {
			if (parent->left == curr) {
				parent->left = curr->right;
				delete curr;
			} else {
				parent->right = curr->right;
				delete curr;
			}
		} else {
			if (parent->left == curr) {
				parent->left = curr->left;
				delete curr;
			} else { 
				parent->right = curr->left;
				delete curr;
			}
		}
		return;
	}

	if (curr->left == NULL && curr->right == NULL) {
		if (parent->left == curr) { 
			parent->left = NULL;
		} else { 
				parent->right = NULL;
		}
		delete curr;
	return;
	}

	if (curr->left != NULL && curr->right != NULL) {
		Node* chNode;
		if(d < this->root->data) {
			chNode = curr->right;
		} else {
			chNode = curr->left;
		}
		if ((chNode->left == NULL) && (chNode->right == NULL)) {
			curr = chNode;
			delete chNode;
			if(d < this->root->data) {
				curr->right = NULL;
			} else {
				curr->left = NULL;
			}
		} else {
				if ((curr->right)->left != NULL) {
				Node* lcurr;
				Node* lcurrp;
				lcurrp = curr->right;
				lcurr = (curr->right)->left;
				while (lcurr->left != NULL) {
					lcurrp = lcurr;
					lcurr = lcurr->left;
				}
				curr->data = lcurr->data;
				delete lcurr;
				lcurrp->left = NULL;
			} else {
				Node* tmp;
				tmp = curr->right;
				curr->data = tmp->data;
				curr->right = tmp->right;
				delete tmp;
			}
		}
		return;
	}
}


void BinarySearch::insert(int data) {
	root = insertRec(data,root);
}

Node* BinarySearch::insertRec(int value, Node* temp){
	if(temp == NULL) {
		temp = new Node(value);
		temp->data = value;
		temp->left = NULL;
		temp->right = NULL;
	} else if(value < temp->data) {
		temp->left = insertRec(value, temp->left);
	} else if(value > temp->data) {
		temp->right = insertRec(value, temp->right);
	}
	return temp;
}

Node* BinarySearch::getRoot() {
	return this->root;
}

bool BinarySearch::empty() {
	return (this->root == NULL);
}

Node* BinarySearch::isEmpty(Node* temp) {
	if(temp == NULL) {
		return NULL;
	} else {
		isEmpty(temp->left);
		isEmpty(temp->right);
		delete temp;
	}
	return NULL;
}


void BinarySearch::search(int value) {
    if(empty()) {
        std::cout << "Tree is empty!!!" << std::endl;
    } else {
        searchRec(value,root);	
	}
}
	

Node* parent = NULL;
Node* current = NULL;
Node* leftChild = NULL;
Node* rightChild = NULL;

Node* BinarySearch::searchRec(int key, Node* temp) {
 
	if (temp == NULL) {
		return NULL;
	}

	if(temp->data == key) {
		if(temp == root){
			parent = NULL;
		}

		if(temp->left == NULL) {
			leftChild = NULL;
    		std::cout << "left : NULL " << std::endl;
		} else {
			leftChild = temp->left;
			std::cout << "left : " << leftChild->data << std::endl;
		}

		if(temp->right == NULL) {
			rightChild = NULL;
			std::cout << "right : NULL " << std::endl;
		} else {
			rightChild = temp->right;
			std::cout << "right : " << rightChild->data << std::endl;
		}
		current = temp;
		std::cout << "parent : " << parent->data << std::endl;
		std::cout << "current : " << current->data << std::endl;
		return current ;
	}

	if (temp->data < key){
		parent = temp;
		return searchRec(key, temp->right);
	} else {
		parent = temp;
		return searchRec(key, temp->left);
	}
	return temp;
}


void BinarySearch::inOrder(Node* value) {
	if(value == NULL) {
		return;
	}
	inOrder(value->left);
	std::cout << value->data << " ";
	inOrder(value->right);
}

void BinarySearch::preOrder(Node* value) {
	if(value == NULL) {
		return;
	}
	std::cout << value->data << " ";
	inOrder(value->left);
	inOrder(value->right);
}

void BinarySearch::postOrder(Node* value) {
	if(value == NULL) {
		return;
	}
	inOrder(value->left);
	inOrder(value->right);
	std::cout << value->data << " ";
}

void BinarySearch::printOrders(){
	if(empty()) {
		std::cout << "Tree is Empty" << std::endl;
	} else {
		std::cout << "Pre-Orders : ";
		preOrder(root);
		std::cout << std::endl;
		std::cout << "Orders : ";
		inOrder(root);
		std::cout << std::endl;
		std::cout << "Post-Orders : ";
		postOrder(root);
	}
	std::cout << std::endl;
}

void BinarySearch::print(){
	if(empty()) {
		std::cout << "Tree is Empty" << std::endl;
	} else {
		std::cout << "Tree elements : ";
		inOrder(root);
	}
	std::cout << std::endl;
}
