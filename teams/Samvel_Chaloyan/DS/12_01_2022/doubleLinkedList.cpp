#include <iostream>

class Node {
	public:
		int data;
		Node* prev;
		Node* next;
		Node();
		Node(int);
};

Node::Node() {
	this -> prev = NULL;
	this -> next = NULL;
}

Node::Node(int data) {
	this -> prev = NULL;
	this -> next = NULL;
	this -> data = data;
}

class DoubleLinkedList {
	private:
		Node* head;
		Node* tail;
	public:
		DoubleLinkedList();
		~DoubleLinkedList();
		void pushFront(int);
		void pushBack(int);
		void popFront();
		void popBack();
		void insertAt(int, int);
		void removeSpecNode(int);
		void printLinkedList();
};

DoubleLinkedList::DoubleLinkedList() {
	this -> head = NULL;
	this -> tail = NULL;
}

DoubleLinkedList::~DoubleLinkedList() {
	while (this -> head -> next != NULL) {
		this -> head = this -> head -> next;
		delete this -> head -> prev;
	}	
	delete this -> head;
}

void DoubleLinkedList::pushFront(int data) {
	Node* node = new Node(data);
	if (this -> head == NULL) {
		this -> head = node;
		this -> tail = node;	
	} else {
	this -> head -> prev = node;
	node -> next = this -> head;
	this -> head = node;
	}
}

void DoubleLinkedList::pushBack(int data) {
	Node* node = new Node(data);
	if (this -> tail == NULL) {
		this -> tail = node;
		this -> head = node;
	} else {
		this -> tail -> next = node;
		node -> prev = this -> tail;
		this -> tail = node;
	}
}

void DoubleLinkedList::popFront() {
	if (this -> head != NULL) {
		Node* prevHead = this -> head;
		this -> head = prevHead -> next;
		delete prevHead;
	} else {
		std::cout << "There are NO Linked List" << std::endl;
	}
}

void DoubleLinkedList::popBack() {
	if (this -> tail != NULL) {
		this -> tail = this -> tail -> prev;
		delete this -> tail -> next;
		this -> tail -> next =  NULL;
	} else {
		std::cout << "There are NO Linked List" << std::endl;
	}
}

void DoubleLinkedList::insertAt(int data, int position) {
	Node* newNode = new Node(data);
	Node* tmp = this -> head;
	if (position <= 0) {
		std::cout << "The position should be positive integer." << std::endl;
	}
	else if (position == 1) {
		newNode -> next = this -> head;
		this -> head -> prev = newNode;
		this -> head = newNode;
	} else {
		for (int i = 1; i < position; ++i) {
			if (tmp != NULL) {
				tmp = tmp -> next;
			}
		}
	}

	if (tmp != NULL) {
		newNode -> next = tmp -> next;
		newNode -> prev = tmp;
		tmp -> next = newNode;
		if (tmp -> next != NULL) {
			newNode -> next -> prev = newNode;
		} else {
			newNode = this -> tail;
		}
	}
}

void DoubleLinkedList::removeSpecNode(int data) {
	Node* tmp = this -> head;
	while (tmp != NULL) {
		if (tmp -> data == data) {
			tmp -> next -> prev = tmp -> prev;
			delete tmp;	
		} else {
			tmp = this -> head -> next;
		}

		if (tmp -> data == data) {
			tmp -> next -> prev = tmp -> prev;;
			tmp -> next = tmp -> prev -> next;
			delete tmp;
		} else {
			std::cout << "There is NO matching data" << std::endl;
		}


	}
}

void DoubleLinkedList::printLinkedList() {
	Node* current = this -> head;
	std::cout << "Head -> ";
       	while (current != NULL) {
		std::cout << current -> data << " -> ";
		current = current -> next;
	}
	std::cout << "Tail" << std::endl;	
}

int main() {
	DoubleLinkedList* list = new DoubleLinkedList();
	list -> pushFront(8);
	list -> pushFront(4);
	list -> pushFront(1);
	list -> pushFront(0);
	std::cout << "Double Linked List" << std::endl;
	list -> printLinkedList();	
	list -> popBack();
	list -> printLinkedList();
	delete list;
	return 0;
}
