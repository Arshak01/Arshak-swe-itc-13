#include <iostream>

class Node {
	public:
		int data;
		Node* next;
		Node(int data) {
			this -> data = data;
			this -> next = NULL;
		}
};

class Queue {
	private:
		Node* head;
		Node* tail;
		int size;
	public:
		Queue() {
			this -> size = 0;
			this -> head = this -> tail = NULL;
		}

		void enQueue(int num);
		void deQueue();
		bool isEmpty();
		int getSize();
		int getHead();
		int getTail();
};

void Queue::enQueue(int num) {
	this -> size++;
	Node* tmp = new Node(num);
	if (this -> tail == NULL) {
		this -> head = this -> tail = tmp;
		return;
	}

	tail -> next = tmp;
	tail = tmp;
}

void Queue::deQueue() {
	if (this -> head == NULL) {
		return;
	}

	this -> size--;
	Node* tmp = this -> head;
	this -> head = this -> head -> next;

	if (this -> head == NULL) {
		this -> head = NULL;
	}
	delete tmp;
}

bool Queue::isEmpty() {
	return (this -> head == this -> tail);
}

int Queue::getSize() {
	return this -> size;
}

int Queue::getHead() {
	return this -> head -> data;
}
int  Queue::getTail() {
	return this -> tail -> data;
}

int main() {
	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.enQueue(60);
	q.deQueue();
	if (q.isEmpty()) {
		std::cout << "The Queue is empty!" << std::endl;
	} else {
		std::cout << "The Queue is NOT empty!" << std::endl;
	}
	std::cout << "Queue Size: " << q.getSize() << std::endl;
	std::cout << "Queue Head: " << q.getHead() << std::endl;
	std::cout << "Queue Tail: " << q.getTail() << std::endl;
	return 0;
}
