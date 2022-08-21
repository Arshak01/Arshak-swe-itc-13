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
		tmp->setPrev(NULL);
		delete tmp;
		tmp = NULL;
		this->length--;
	}

	void push(int val) {
		Node *tmp = this->head;
		this->head = new Node(val, tmp);
		tmp = NULL;
		this->length++;
	}

	int size() const {
		return this->length;
	}

	bool isEmpty() const {
		return (this->length == 0) ? true: false;
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
		Node *tmp;
		while(this->head != NULL){
			tmp = this->head;
			this->head = this->head->getPrev();
			delete tmp;
		}
	}

};

int main() {
	Stack stack;
	std::cout << "isEmpty() = " << stack.isEmpty() << std::endl;
	std::cout << "***Adding 1, 2, 3 to Stack ***" << std::endl;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.print();
	std::cout << "size = " << stack.size() << std::endl;
	std::cout << "***Popping out***" << std::endl;
	stack.pop();
	stack.print();
	std::cout << "size = " << stack.size() << std::endl;
	std::cout << "isEmpty() = " << stack.isEmpty() << std::endl;
	std::cout << "top() = " << stack.top() << std::endl;
	return 0;
}
