#include <iostream>
#include "List.hpp"
#include "Iterator.hpp"

List::List() {
	this->length = 0;
	this->tail = NULL;
	this->head = NULL;
}

List::List(List& obj) {
	Iterator i = obj.getTail();
	for(i = i.begin(); i.getIt() != NULL; ++i) {
		this->pushFront(i.getIt()->getNum());
	}
}

Node* List::getHead() const {
	return this->head;
}

Node* List::getTail() const {
	return this->tail;
}

void List::setHead(Node *head) {
	this->head = head;
}

void List::setTail(Node *tail) {
	this->tail = tail;
}

//To avoid code duplicatoin
void List::firstElem(int val) {
	if(this->length == 0) {
		this->head = new Node(val, NULL, NULL);
		this->tail = this->head;
		this->length++;
	}
}

//without creating tmp
void List::pushFront(int val) {
	if(this->length > 0) {
		this->head->setNext(new Node(val, NULL, this->head));
		this->head = this->head->getNext();
		this->length++;
	} else {
		firstElem(val);
	}
}

//without creating tmp
void List::pushBack(int val) {
	if(this->length > 0) {
		this->tail->setPrev(new Node(val, this->tail, NULL));
		this->tail = this->tail->getPrev();
		this->length++;
	} else {
		firstElem(val);
	}
}

//without creating tmp
void List::popBack() {
	if(this->length == 0) {
		std::cout << "There is nothing to pop" << std::endl;
	} else {
		this->tail = this->tail->getNext();
		delete this->tail->getPrev();
		this->tail->setPrev(NULL);
		this->length--;
	}
}

//without creating tmp
void List::popFront() {
	if(this->length == 0) {
		std::cout << "There is nothing to pop" << std::endl;
	} else {
		this->head = this->head->getPrev();
		delete this->head->getNext();
		this->head->setNext(NULL);
		this->length--;
	}
}

//without creating tmp
void List::insert(unsigned int position, int data) {
	if(position == 0) {
		this->pushBack(data);
	} else if(position == this->length) {
		this->pushFront(data);
	} else{
		Iterator it = this->tail;
		for(int i = 0; i < position; ++i) {
			++it;
		}
		it.getIt()->getPrev()->setNext(new Node(data, it.getIt(), NULL));
		it.getIt()->getPrev()->getNext()->setPrev(it.getIt()->getPrev());
		it.getIt()->setPrev(it.getIt()->getPrev()->getNext());
		this->length++;
	}
}

void List::remove(int data) {
	if(this->length == 0) {
		std::cout << "List is empty!" << std::endl;
		return;
	}
	Iterator i = this->tail;
	for(i; i.getIt()->getNum() != data; i++) {
		if(i.getIt() == NULL) {
			std::cout << "No such data in the list" << std::endl;
			return;
		}
	}
	if(i.getIt() == this->tail) {
		this->popBack();
		return;
	} else if(i.getIt() == this->head) {
		this->popFront();
		return;
	} else {
		Node *tmp = i.getIt();
		i.getIt()->getPrev()->setNext(i.getIt()->getNext());
		i.getIt()->getPrev()->getNext()->setPrev(i.getIt()->getPrev());
		delete tmp;
		this->length--;
	}
}

void List::print() {
	Iterator i = this->tail;
	for(i = i.begin(); i.getIt() != NULL; ++i) {
		i.printIt();
	}
}
