#include "Node.hpp"
#include <iostream>

Node::Node() {
	std::cout << "Node constructor started" << std::endl;
	this->num = 0;
	this->next = NULL;
	this->prev = NULL;
	std::cout << "Node constructor finished" << std::endl;
}

Node::Node(int num, Node *next, Node *prev) {
	this->num = num;
	this->next = next;
	this->prev = prev;
}

int Node::getNum() const {
	return this->num;
}

Node* Node::getNext() const {
	return this->next;
}

Node* Node::getPrev() const {
	return this->prev;
}

void Node::setNum(int num) {
	this->num = num;
}

void Node::setNext(Node *next) {
	this->next = next;
}

void Node::setPrev(Node *prev) {
	this->prev = prev;
}
