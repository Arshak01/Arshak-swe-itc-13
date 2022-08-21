#include <iostream>

class Node {
public:
    int num;
	Node* prev;

    Node() {
        this->num = 0;
		this->prev = NULL;
	}
};

class Stack {
	Node* head;
	unsigned int size;
public:
    Stack() {
		this->head = NULL;
		this->size = 0;
	}
    void push(int value) {
		Node* temp = new Node();
		temp->num = value;
        if (head == NULL){
			this->head = temp;
			temp->prev = NULL;
		} else {
			temp->prev = head;
			this->head = temp;
		}
		size++;
	}
	void pop() {
		if(this->head == NULL) {
			std::cout << "No item in stack" << std::endl;
		} else {
			Node* temp = head;
			head = head->prev;
			delete(temp);
		}
		size--;
	}

	int getSize() const {
		return this->size;
	}

	bool isEmpty() {
        return (this->head == NULL)?true:false; 
	}

	int top() {
		return head->num;
	}
    
	void print() {
		if (isEmpty()){
			std::cout << "Stack is empty" << std::endl;
		} else {
			Node* last = head;
			std::cout << "Stack elements ";
			while(last != NULL) {
				std::cout << last->num << "  ";
				last = last->prev;
				}
				std::cout << std::endl;
		}
	}


};

int main() {
    Stack s1;
	std::cout << "Empty  " << s1.isEmpty() << std::endl;
    s1.push(10);
	s1.print();
	s1.push(20);
	std::cout << "Stack before pop ";
	s1.print();
	s1.pop();
	std::cout << "stack after pop  " ;
	s1.print();
	std::cout << "stack size  " << s1.getSize() << std::endl;
    s1.push(45);
	std::cout << "Top is " << s1.top() << std::endl;

    return 0;
}
