#include <iostream>
#include "Node.hpp"
#include "Stack.hpp"

Stack::Stack() {
	this->length = 0;
	this->head = NULL;
}

void Stack::pop() {
	if(isEmpty()) {
		return;
	}
	Node *tmp = this->head;
	this->head = this->head->getPrev();
	tmp->setPrev(NULL);
	delete tmp;
	tmp = NULL;
	this->length--;
}

void Stack::push(char val) {
	Node *tmp = this->head;
	this->head = new Node;
	this->head->setSymb(val);
	this->head->setPrev(tmp);
	tmp = NULL;
	this->length++;
}

int Stack::size() const {
	return this->length;
}

bool Stack::isEmpty() const {
	return (this->length == 0) ? true : false;
}

char Stack::top() const {
	if(isEmpty()) {
		return 0;
	}
	return this->head->getSymb();
}

void Stack::print() {
	Node *tmp = this->head;
	while(tmp != NULL) {
		std::cout << tmp->getSymb() << std::endl;
		tmp = tmp->getPrev();
	}
}

Stack::~Stack() {
	Node *tmp;
	while(this->head != NULL) {
		tmp = this->head;
		this->head = this->head->getPrev();
		delete tmp;
	}
	delete this->head;
	this->head = NULL;
}
