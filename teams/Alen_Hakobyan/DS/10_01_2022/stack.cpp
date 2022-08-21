#include <iostream>

class Node {
public:
	int data;
	Node *link;
	Node() {
		this->data = 0;
	}
};

class Stack {
private:
	int size;
	Node *top = NULL;
public:
	Stack () {
		this->size = 0;
	}
	bool empty() {
			return top == NULL;
	}
	void push (int value) {
		Node *ptr = new Node();
		ptr->data = value;
		ptr->link = top;
		top = ptr;
		std::cout << value << " has been inserted." << std::endl;
		this->size++;
	}
	int sizeStack() {
		return this->size;
	}
	void pop() {
		if (empty()) {
			std::cout << "Stack is Empty" << std::endl;
		}
		else {
			Node *ptr = top;
			top = top -> link;
			this->size--;
			delete ptr;
		}
	}
	void showTop() {
		if (empty()) {
			std::cout << "Stack is Empty" << std::endl;
		}
		else {
			std::cout << "Element at top is : " << top->data << std::endl;
		}
	}
	void displayStack() {
		if (empty()) {
			std::cout<<"Stack is Empty" << std::endl;
		}
		else {
			Node *temp = top;
			std::cout << "Stack elements is : ";
			while (temp != NULL) {
				std::cout << temp->data << " ";
				temp = temp->link;
			}
			std::cout << std::endl;
		}
	}
	~Stack() {
    	while (this->top != NULL) {
        	Node *ptr = top;
        	top = top->link;
        	delete ptr;
    	}
	}
};

int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.displayStack();
	std::cout << "Size of stack is : " << s.sizeStack() << std::endl;
	s.showTop();
	s.pop();
	std::cout << "After pop ";
	std::cout << "Size of stack is : " << s.sizeStack() << std::endl;
	s.showTop();
	s.displayStack();

	return 0;
}
