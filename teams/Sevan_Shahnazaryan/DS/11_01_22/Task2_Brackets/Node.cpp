#include "Node.hpp"
#include <iostream>

Node::Node() {
	this->symb = 0;
	this->prev = NULL;
}

Node::Node(char symb, Node *prev) {
	this->symb = symb;
	this->prev = prev;
}

char Node::getSymb() const {
	return this-> symb;
}

void Node::setSymb(char symb) {
	this->symb = symb;
}

Node* Node::getPrev() const {
	return this->prev;
}

void Node::setPrev(Node *prev) {
	this->prev = prev;
}

/*Node::~Node() {
	delete this->prev;
}*/
