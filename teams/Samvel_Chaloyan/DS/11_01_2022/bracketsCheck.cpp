#include <iostream>

class Node {
	public:
		char data;
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

		void push(char num);
		void pop();
		void displayStack();
		bool isEmpty();
		char topEl();
		int stackSize();
};

void Stack::push(char num) {
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

char Stack::topEl() {
	if (this -> top == NULL) {
		return ' ';
	} else {
	return this -> top -> data;
	}
}

int Stack::stackSize() {
	return this -> size;
}

bool bracketsCheck(std::string expression) {
	Stack* s = new Stack();
	for (int i = 0; i < expression.length(); ++i) {
		if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
			s -> push(expression[i]);
		} 
		
		if (expression[i] == ')' && (s -> topEl() == '{' || s -> topEl() == '[' || s -> isEmpty())) {
			return false;
		}

		if (expression[i] == '}' && (s -> topEl() == '(' || s -> topEl() == '[' || s -> isEmpty())) {
			return false;
		}

		if (expression[i] == ']' && (s -> topEl() == '(' || s -> topEl() == '{' || s -> isEmpty())) {
			return false;
		}

		if (s -> topEl() == '(' && expression[i] == ')') {
			s -> pop();
		} else if (s -> topEl() == '{' && expression[i] == '}') {
			s -> pop();
		} else if (s -> topEl() == '[' && expression[i] == ']') {
			s -> pop();
		} else {
			continue;
		}
	} 
	return (s -> isEmpty());
}

int main() {
	std::string expression;
	std::cout << "Enter sequence of brackets {, [, (, ), ], }" << std::endl;
	std::cin >> expression;
	if (bracketsCheck(expression)) {
		std::cout << "The combination of brackets is Correct" << std::endl;
	} else {
		std::cout << "The combination of brackets is Wrong" << std::endl;
	}
	return 0;
}
