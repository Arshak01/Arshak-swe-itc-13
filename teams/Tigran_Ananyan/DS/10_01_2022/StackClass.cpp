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

	~Node() {
		delete this->prev;
	}
};

class Stack {
private:
	unsigned int length;
	Node *head;

public:
	Stack() {
		this->length = 0;
		this->head = NULL;
	}

	void pop() {
		if(isEmpty()) {
			return;
		}
		Node *tmp = this->head;
		this->head = this->head->getPrev();
		tmp->setNum(0);
		tmp->setPrev(NULL);
		delete tmp;
		tmp = NULL;
		this->length--;
	}

	void push(int val) {
		Node *tmp = this->head;
		this->head = new Node;
		this->head->setNum(val);
		this->head->setPrev(tmp);
		tmp = NULL;
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

	int top() const {
		if(isEmpty()) {
			return 0;
		}
		return this->head->getNum();
	}

	void print() {
		Node *tmp = this->head;
		while(tmp != NULL) {
			std::cout << tmp->getNum() << std::endl;
			tmp = tmp->getPrev();
		}
	}

	~Stack() {
		delete this->head;
		this->head = NULL;
	}

};

int main() {
	Stack s;
	std::cout << "isEmpty() = " << s.isEmpty() << std::endl;
	std::cout << "Pushing, Stack = {50, 15, 120}" << std::endl;
	s.push(120);
	s.push(15);
	s.push(50);
	s.print();
	std::cout << "size = " << s.size() << std::endl;
	std::cout << "Popping" << std::endl;
	s.pop();
	s.print();
	std::cout << "size = " << s.size() << std::endl;
	std::cout << "isEmpty() = " << s.isEmpty() << std::endl;
	std::cout << "top() = " << s.top() << std::endl;
	return 0;
}
