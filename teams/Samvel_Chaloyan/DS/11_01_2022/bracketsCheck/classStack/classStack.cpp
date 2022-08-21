#include <iostream>
#include "classStack.h"

Stack::Stack() {
	this -> top = NULL;
	this -> size = 0;
}

Stack::~Stack() {
	while (!isEmpty()) {
		pop();
	}
}
    
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


