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

class Queue {
	Node* head;
	Node* tail;
	unsigned int size;
public:
    Queue() {
		this->tail = NULL;
		this->head = NULL;
		this->size = 0;
	}

	int getSize() const {
        return this->size;
	}
	
	bool isEmpty() {
		return (this->size==0)?true:false;
	}

	void push(int value) {
		Node* temp = new Node();
		temp->num = value;
        if (head == NULL && tail == NULL){
			this->head = temp;
			this->tail = temp;
		} else {
			tail->prev = temp;
			tail = temp;
		}
		size++;
	}

	void pop() {
		if(isEmpty()) {
			std::cout << "No item in stack" << std::endl;
		} else {
			Node* temp = head;
			head = head->prev;
			delete(temp);
		}
		size--;
	}

	int front() {
        return head->num;
	}

	int back() {
		return tail->num;
	}

	void print() {
        if (isEmpty()){
			std::cout << "Queue is empty" << std::endl;
		} else {
			Node* temp = head;
			std::cout << "Queue elements ";
			while(temp != NULL) {
				std::cout << temp->num << "  ";
				temp = temp->prev;
				}
				std::cout << std::endl;
		}
	}
};


int main() {
	Queue q;
	std::cout << "Is empty " << q.isEmpty() << std::endl; 
	q.push(10);
	q.print();
	q.push(20);
	q.push(30);
	std::cout << "Queue before pop ";
	q.print();
	q.pop();
	std::cout << "Queue after pop ";
	q.print(); 
    std::cout << "Front of Queue ";
	std::cout << q.front() << std::endl;
	std::cout << "Back of Queue ";
	std::cout << q.back() << std::endl;
	std::cout << "Size " << q.getSize();



    return 0;
}
