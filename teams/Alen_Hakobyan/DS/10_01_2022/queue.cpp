#include <iostream>

class Node {
public:
	int data;
	Node *next;
	Node() {
		this->data = 0;
	}
};

class Queue{
public:
	int size;
	Node *front, *rear;
	Queue() {
		front = rear = NULL;
		this->size = 0;
	}
	void pushBack(int value) {
		this->size++;
		Node *temp = new Node;
		if(temp == NULL){
			std::cout << "Overflow" << std::endl;
		return;
		}
		temp->data = value;
		temp->next = NULL;
		if (front == NULL) {
			front = rear = temp;
		}
		else {
			rear->next = temp;
			rear = temp;
		}
		std::cout << value << " has been inserted." << std::endl;
	}
	int sizeQueue() {
		return this->size;
	}
	bool empty() {
		return (front == NULL && rear == NULL);
	}
	void display() {
		if(front == NULL) {
			std::cout << "Underflow." << std::endl;
			return;
		}
		Node *temp = front;
		while (temp){
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	void pop() {
		if (front == NULL) {
			std::cout << "Underflow" << std::endl;
			return;
		}
		std::cout << front->data << " is being deleted " << std::endl;
		if(front == rear) {
			front = rear = NULL;
		}
		else {
			front = front->next;
		}
		this->size--;
	}
	void showFront() {
		if (empty()) {
			std::cout << "Queue is empty" << std::endl;
		}
		else {
			std::cout << "Element at front is : " << front->data << std::endl;
		}
	}
	void showBack() {
		if (empty()) {
			std::cout << "Queue is empty" << std::endl;
		}
		else {
			std::cout << "Element at back is : " << rear->data << std::endl;
		}
	}
	~Queue() {
		while (front != NULL) {
			Node *temp = front;
			front = front->next;
			delete temp;
		}
		rear = NULL;
	}
}; 
 
int main(){
	Queue q;
	q.pushBack(10);
	q.pushBack(20);
	q.pushBack(30);
	q.pushBack(40);
	q.pushBack(50);
	std::cout << "Size of queue is : " << q.sizeQueue() << std::endl;
	q.showFront();
	q.showBack();
	q.display();
	q.pop();
	std::cout << "After pop size of queue is : " << q.sizeQueue() << std::endl;
	q.showFront();
	q.display();

	return 0;
}
