#include <iostream>

class Node {
private:
	Node *prev;
	int num;

public:
	Node() {
		this->num = 0;
		this->prev = NULL;
	}

	Node(int num, Node *prev) {
		this->num = num;
		this->prev = prev;
	}

	int getNum() const {
		return this-> num;
	}

	void setNum(int num) {
		this->num = num;
	}

	Node* getPrev() const {
		return this->prev;
	}

	void setPrev(Node *prev) {
		this->prev = prev;
	}
};

class Queue {
private:
	unsigned int length;
	Node *tail;
	Node *head;

public:
	Queue() {
		this->length = 0;
		this->head = NULL;
		this->tail = NULL;
	}

	void popFront() {
		if(isEmpty()) {
			return;
		}
		Node *tmp = this->head;
		this->head = this->head->getPrev();
		tmp->setNum(0);
		delete tmp;
		tmp = NULL;
		this->length--;
	}

	void pushBack(int val) {
		Node *tmp = new Node;
		tmp->setNum(val);
		tmp->setPrev(NULL);
		if(this->isEmpty()) {
			this->head = tmp;
			this->tail = tmp;
		} else {
			this->tail->setPrev(tmp);
			this->tail = tmp;
		}
		this->length++;
	}

	int size() const {
		return this->length;
	}

	bool isEmpty() const {
		return (this->length == 0) ? true : false;
	}

	int front() const {
		if(isEmpty()) {
			return 0;
		}
		return this->head->getNum();
	}

	int back() const {
		if(isEmpty()) {
			return 0;
		}
		return this->tail->getNum();
	}

	void print() {
		Node *tmp = this->head;
		while(tmp != NULL) {
			std::cout << tmp->getNum() << std::endl;
			tmp = tmp->getPrev();
		}
	}

	~Queue() {
		Node *tmp;
		while(this->head != NULL) {
			tmp = this->head;
			this->head = this->head->getPrev();
			delete tmp;
		}
		this->tail = NULL;
		this->head = NULL;
	}

};

int main() {
	Queue queue;
	std::cout << "isEmpty() = " << queue.isEmpty() << std::endl;
	std::cout << "***Adding 1, 2, 3 to Queue ***" << std::endl;
	queue.pushBack(1);
	queue.pushBack(2);
	queue.pushBack(3);
	queue.print();
	std::cout << "size = " << queue.size() << std::endl;
	std::cout << "***Poping out***" << std::endl;
	queue.popFront();
	queue.print();
	std::cout << "size = " << queue.size() << std::endl;
	std::cout << "isEmpty() = " << queue.isEmpty() << std::endl;
	std::cout << "front() = " << queue.front() << std::endl;
	std::cout << "back() = " << queue.back() << std::endl;
	return 0;
}
