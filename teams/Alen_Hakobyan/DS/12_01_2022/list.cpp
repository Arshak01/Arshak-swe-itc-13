#include <iostream>
#include "list.h"


Node::Node(int num) {
	this->data = num;
}

List::List() {
	this->front = NULL;
	this->end = NULL;
}

List::List(List& list) {
	Node* temp = list.front;
	Node* temp1 = this->front;
	while(temp != NULL) {
		temp1->next = new Node(temp->data);
		temp1->data = temp->data;
		temp = temp->next;
		temp1 = temp1->next;
	}
}

List::~List() {
	while (front->next != NULL) {
		front = front->next;
		delete front->prev;
		front->prev = NULL;
	}
	delete front;
}

bool List::isEmpty() {
	return (front == NULL && end == NULL);
}

void List::pushBack(int data) {
	Node* temp = new Node(data);
	temp->data = data;
	temp->next = NULL;
	temp->prev = end;
	if(end == NULL) {
		front = temp;
	}
	else {
		end->next = temp;
	}
	end = temp;
}

void List::pushFront(int data) {
	Node* temp = new Node(data);
	temp->data = data;
	temp->next = front;
	temp->prev = NULL;
	if(front == NULL) {
		end = temp;
	}
	else {
		front->prev = temp;
	}
	front = temp;
}

void List::popFront() {
	if(isEmpty()) {
		std::cout << "List is Empty!!!" << std::endl;
	}
	else {
		front = front->next;
		delete front->prev;
		front->prev = NULL;
	}
}

void List::popBack() {
	if(isEmpty()) {
		std::cout << "List is Empty!!!" << std::endl;
	}
	else {
		end = end->prev;
		delete end->next;
		end->next = NULL;
	}
}

void List::remove(int data) {
	Node* ptr = front;
	while(ptr->data != data) {
		ptr = ptr->next;
	}
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	delete ptr;
}

void List::insert(int index, int data) {
	Node* newTemp = new Node(data);
	newTemp->data = data;
	newTemp->next = NULL;
	newTemp->prev = NULL;
	if(index == 0) {
		newTemp->next = front;
		front->prev = newTemp;
		front = newTemp;
	}
	else {
		Node* temp = front;
		for(int i = 1; i < index; ++i) {
			if(temp != NULL) {
				temp = temp->next;
			}
		}
		if(temp != NULL) {
			newTemp->next = temp->next;
			newTemp->prev = temp->prev;
			temp->next = newTemp;
		}
		if(newTemp->next != NULL) {
			newTemp->next->prev = newTemp;
		}
	}
}

void List::print() {
	if(isEmpty()) {
		std::cout << "List is Empty!!!" << std::endl;
	}
	else {
		Node* temp = front;
		std::cout << "List elements is : ";
		while(temp != NULL) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}
	std::cout << std::endl;
}
