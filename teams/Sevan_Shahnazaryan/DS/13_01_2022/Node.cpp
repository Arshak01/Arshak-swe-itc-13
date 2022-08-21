#include <iostream>
#include "Node.hpp"

Node::Node() {
	this->num = 0;
	this->left = NULL;
	this->right = NULL;
}

Node::Node(int num, Node *left, Node *right) {
	this->num = num;
	this->left = left;
	this->right = right;
}


int Node::getNum() const {
	return this->num;
}

Node* Node::getLeft() const {
	return this->left;
}

Node* Node::getRight() const {
	return this->right;
}

void Node::setNum(int num) {
	this->num = num;
}

void Node::setLeft(Node *left) {
	this->left = left;
}

void Node::setRight(Node *right) {
	this->right = right;
}
