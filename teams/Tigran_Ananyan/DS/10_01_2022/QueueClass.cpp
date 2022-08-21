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
		if(this->length == 0) {
			return true;
		} else {
			return false;
		}
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
		delete this->tail;
		delete this->head;
		this->tail = NULL;
		this->head = NULL;
	}

};

int main() {
	Queue q;
	std::cout << "isEmpty() = " << q.isEmpty() << std::endl;
	std::cout << "Pushing, Queue = {12, 34, 56}" << std::endl;
	q.pushBack(12);
	q.pushBack(34);
	q.pushBack(56);
	q.print();
	std::cout << "size = " << q.size() << std::endl;
	std::cout << "Popping" << std::endl;
	q.popFront();
	q.print();
	std::cout << "size = " << q.size() << std::endl;
	std::cout << "isEmpty() = " << q.isEmpty() << std::endl;
	std::cout << "front() = " << q.front() << std::endl;
	std::cout << "back() = " << q.back() << std::endl;
	return 0;
}
