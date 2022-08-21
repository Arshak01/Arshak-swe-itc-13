#include <iostream>

class Node {
	public:
		int data;
		Node* below;		
};

class Stack {
	private:
		Node* top;
		int size;
	public:	
		Stack() {
			this -> top = NULL;			
			this -> size = 0;
		}

		~Stack() {
			while (!isEmpty()) {
				pop();
			}	 
		}

		void push(int num);
		void pop();
		void displayStack();
		bool isEmpty();
		int topEl();
		int stackSize();
};

void Stack::push(int num) {
	this -> size++;
	Node* tmp = new Node;
	tmp -> data = num;
	tmp -> below = this -> top;
	this -> top = tmp;
}

void Stack::displayStack() {
	if (isEmpty()) {
		std::cout << "The stack is empty!" << std::endl;
	} else {
		Node* current = this -> top;
		std::cout << "HEAD: ";
		while (current != NULL) {
			std::cout << current -> data << " -> ";
			current = current -> below;
		}
		std::cout << "END" << std::endl;
	} 
}

bool Stack::isEmpty() {
	return (this -> top == NULL);
}

void Stack::pop() {
	if (!isEmpty()) {
		this -> size--;
		Node* prevTop = this -> top;
		this -> top = prevTop -> below;
		delete prevTop;
	} else {
		std::cout << "The stack is empty and can not be poped!" << std::endl;
	}	
}

int Stack::topEl() {
	return this -> top -> data;
}

int Stack::stackSize() {
	return this -> size;
}

int main() {
	Stack* s = new Stack();
	s -> pop();
	s -> displayStack();
	s -> push(8);	
	s -> push(4);	
	s -> push(1);	
	s -> displayStack();
	std::cout << "The stack size: " << s -> stackSize() << std::endl;
	std::cout << "The stack Head: " << s -> topEl() << std::endl;
	return 0;
}
