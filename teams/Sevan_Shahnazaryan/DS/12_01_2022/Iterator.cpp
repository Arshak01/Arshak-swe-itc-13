#include <iostream>
#include "Iterator.hpp"

Iterator::Iterator() {
	std::cout << "Iterator constructor started" << std::endl;
	this->it = NULL;
	std::cout << "Iterator constructor finished" << std::endl;
}

Iterator::Iterator(Node *it) {
	this->it = it;
}

Node* Iterator::getIt() const {
	return this->it;
}

void Iterator::setIt(Node *it) {
	this->it = it;
}

Iterator Iterator::begin() {
	Iterator finder = *this;
	while(finder.getIt()->getPrev() != NULL) {
		--finder;
	}
	return finder;
}

Iterator Iterator::end() {
	Iterator finder = *this;
	while(finder.getIt()->getNext() != NULL) {
		++finder;
	}
	finder.setIt(finder.getIt()->getNext());
	return finder;
}

//Prefix increment
Iterator& Iterator::operator++() {
	this->it = this->it->getNext();
	return *this;
}

//Postfix increment
Iterator Iterator::operator++(int) {
	Iterator tmp = *this;
	this->it = this->it->getNext();
	return tmp;
}

//Prefix decrement
Iterator& Iterator::operator--() {
	this->it = this->it->getPrev();
	return *this;
}

//Postfix decrement
Iterator Iterator::operator--(int) {
	Iterator tmp = *this;
	this->it = this->it->getPrev();
	return tmp;
}

bool Iterator::operator!=(const Iterator &obj) {
	if(this->getIt()->getNum() != obj.getIt()->getNum() ||
	   this->getIt()->getPrev() != obj.getIt()->getPrev() ||
	   this->getIt()->getNext() != obj.getIt()->getNext()) {
			return true;
	} else {
		return false;
	}
}

void Iterator::printIt() {
	std::cout << this->it->getNum() << std::endl;
}
