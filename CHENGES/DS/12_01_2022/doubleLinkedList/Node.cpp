#include "./Node.hpp"
#include <iostream>

Node::Node() {
		this->data;
		this->next;
		this->prev;
}
Node::Node(int data) {
	this->data = data;
	this->next = NULL;
	this->prev = NULL;
	 
}
