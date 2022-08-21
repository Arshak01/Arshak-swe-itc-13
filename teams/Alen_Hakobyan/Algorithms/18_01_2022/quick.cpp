#include <iostream>
#include "quick.h"

Node::Node(int value) {
	this->next = NULL;
	this->data = value;
}

Quick::Quick() {
	this->head = NULL;
	this->tail = NULL;
}

Quick::~Quick() {
	while(head->next != NULL) {
		head = head->next;
	}
	delete head;
}

void Quick::pushNext(int data) {
	Node* temp = new Node(data);
	if(this->head == NULL) {
		this->head = temp;
		this->tail = temp;
	}
	else {
		this->tail->next = temp;
		this->tail = temp;
	}
}

void Quick::printQuick() {
	Node* temp = head;
	while(temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

Node* Quick::position(Node* first, Node* last) {
	Node* pivot = first;
	Node* front = first;
	int temp = 0;
	while(front != NULL && front != last) {
		if(front->data < last->data) {
			pivot = first;
			temp = first->data;
			first->data = front->data;
			front->data = temp;
			first = first->next;
		}
		front = front->next;
	}
	temp = first->data;
	first->data = last->data;
	last->data = temp;
	return pivot;
}

Node* Quick::lastNode() {
	Node* temp = this->head;
	while(temp != NULL && temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
}

void Quick::sort(Node* first, Node* last) {
	if(first == last) {
		return;
	}
	Node* pivot = position(first, last);
	if(pivot != NULL && pivot->next != NULL) {
		sort(pivot->next, last);
	}
	if(pivot != NULL && first != pivot) {
		sort(first, pivot);
	}
}

