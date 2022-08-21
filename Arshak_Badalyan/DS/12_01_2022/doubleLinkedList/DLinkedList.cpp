#include <iostream>
#include "./DLinkedList.hpp"

DLinkedList::DLinkedList() {
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

DLinkedList::DLinkedList(const DLinkedList& dl) {
        Node* temp = dl.head;
        while(temp!=NULL) {
            pushFront(temp->data);
            temp=temp->next;
        }
}

void DLinkedList::pushBack(int data) {
	Node* temp = new Node(data);

	if(this->tail == NULL) {
		this->head = temp;
	} else {
		temp->prev = tail;
		tail->next = temp;
	}
	this->tail = temp;
	++this->size;
}

void DLinkedList::pushFront(int data) {
	Node* temp = new Node(data);

	if(this->head == NULL) {
		this->tail = temp;
	} else {
		temp->next = head;
		head->prev = temp;
	}
	this->head = temp;
	++this->size;
}

void DLinkedList::popBack() {
	if(this->head == NULL && this->tail == NULL) {
		std::cout << "double linkedlist is empty !!!" << std::endl;
	} else if(this->head->next == NULL && this->head->prev == NULL) {	
		delete head;
		--this->size;
	} else {
		Node* temp = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = NULL;
		delete temp;
		--this->size;
	}
}

void DLinkedList::popFront() {
	if(this->head == NULL && this->tail == NULL) {
		std::cout << "Double LinkedList is empty !!!" << std::endl;
	} else if(this->head->next == NULL && this->head->prev == NULL) {
		delete head;			
		--this->size;	
	} else {
		Node*temp = this->head;
		this->head = this->head->next;
		this->head->prev = NULL;
		delete temp;
		--this->size;			
	}
}

void DLinkedList::insertByElement(int element, int data) {
	Node* temp = head;
	while(temp != NULL){
		if(temp->data == element) {
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = NULL;
			newNode->prev = NULL;	
			if(newNode != NULL) {	
				newNode->next = temp;
				newNode->prev = temp->prev;
				temp->prev->next = newNode;
			}
			if(newNode->next != NULL) {
				newNode->next->prev = newNode;
			}
			++this->size;
		}
		temp = temp->next;
	}
}

void DLinkedList::insert(int position, int data) {
	Node* temp = head;
	int ps = 0;	
	while(temp != NULL){
		if(ps == position) {
			std::cout << ps << std::endl;
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = NULL;
			newNode->prev = NULL;	
			if(newNode != NULL) {	
				newNode->next = temp;
				newNode->prev = temp->prev;
				temp->prev->next = newNode;
			}
			if(newNode->next != NULL) {
				newNode->next->prev = newNode;
			}
			++this->size;
		}
		++ps;
		temp = temp->next;
	}
}

void DLinkedList::remove(int data) {
	Node* temp = this->head;
	while(temp != NULL && temp->data != data) {
		if(temp->data != data ) {
			std::cout << "Wrong data " << std::endl;
			return;
		}
		temp=temp->next;
	}
	if(temp->prev == NULL){
		this->head = this->head->next;
		this->head->prev = NULL;
		--this->size;		
	} else if(temp->next == NULL) {
		temp = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = NULL;
		--this->size;
	} else {
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		--this->size;
	}
	delete temp;
}

void DLinkedList::print() {
	Node* temp;
	if(this->head == NULL){
		std::cout << "Double Linked List is empty !" << std::endl;
	} else {
		temp = this->head;
		std::cout<<"DLinkedList elements are: ";
		while(temp != NULL) {
			std::cout << " <-> " << temp-> data;
			temp = temp-> next;
		}	
		std::cout << std::endl;
	}
}

int DLinkedList::getHead() {
	return this->head->data;
}

int DLinkedList::getTail() {
	return this->tail->data;
}

int DLinkedList::getSize() {
	return this->size;
}

DLinkedList::~DLinkedList() {
	while (this->head != NULL) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}
