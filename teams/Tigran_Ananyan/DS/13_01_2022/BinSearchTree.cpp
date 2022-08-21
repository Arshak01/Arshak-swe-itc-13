#include <iostream>
#include "BinSearchTree.hpp"


Node::Node(int data) {
	this->data = data;
	this->left = NULL;
	this->right = NULL;
}

BinSearchTree::BinSearchTree() {
	this->root = NULL;
}

BinSearchTree::~BinSearchTree() {
	root = makeEmpty(root);
}

Node* BinSearchTree::makeEmpty(Node* temp) {
	if(temp == NULL) {
		return NULL;
	}
	else {
		makeEmpty(temp->left);
		makeEmpty(temp->right);
		delete temp;
	}
	return NULL;
}

bool BinSearchTree::isEmpty() {
	return (root == NULL);
}

void BinSearchTree::remove(int data) {
	if(isEmpty()) {
		std::cout << "Nothing to delete!!!" << std::endl;
	}
	else {
		root = remove(data,root);
		std::cout << std::endl;
	}
}

Node* BinSearchTree::remove(int data, Node* temp) {
	Node* temp1;
	if(temp == NULL) {
		return NULL;
	}
	else if(data < temp->data) {
		temp->left = remove(data, temp->left);
	}
	else if(data > temp->data) {
		temp->right = remove(data, temp->right);
	}
	else {
		temp1 = temp;
		if(temp->left == NULL) {
			temp = temp->right;
		}
		else if(temp->right == NULL) {
			temp = temp->left;
		}
		delete temp1;
	}
	return temp;
}

void BinSearchTree::insert(int data) {
	root = insert(data,root);
}

Node* BinSearchTree::insert(int data, Node* temp){
	if(temp == NULL) {
		temp = new Node(data);
		temp->data = data;
		temp->left = temp->right = NULL;
	}
	else if(data < temp->data) {
		temp->left = insert(data, temp->left);
	}
	else if(data > temp->data) {
		temp->right = insert(data, temp->right);
	}
	return temp;
}

void BinSearchTree::order(Node* value) {
	if(value == NULL) {
		return;
	}
	order(value->left);
	std::cout << value->data << " ";
	order(value->right);
}

void BinSearchTree::print(){
	if(isEmpty()) {
		std::cout << "Tree is Empty!!!" << std::endl;
	}
	else{
		std::cout << "Tree elements : ";
		order(root);
	}
	std::cout << std::endl;
}
