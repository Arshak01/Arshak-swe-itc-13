#include <iostream>

struct Node {
	int data;
	Node* next;

	Node() {
		this->data = 0;
		this->next = NULL;
	}
};

class Queue {
	Node* head; 
	Node* tail; 
	int size;
	
public:
	Queue(){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	
	int getSize(){
		return  this->size;
	}

	void push_back(int value){
		Node* temp = new Node();
		temp-> data = value;

		if(head == NULL && tail == NULL){
			head = temp;
			tail = temp;
			temp-> next = NULL;
		} else {
			tail-> next = temp;
			tail = temp;
		}
		size++;
	}

	void pop_front() {
		if(this-> head == NULL){
			this-> tail = NULL;
			std::cout << "Queue is empty !" << std::endl;
		}else{
			Node* temp = head;
			head = head-> next;
			delete(temp);
		}
		size--;
	}

	int front() {
		return head->data;
	}

	int back() {
		return tail->data;
	}
	
	bool empty(){
		return this-> head == NULL && this-> tail == NULL;
	} 

	void isEmpty(){
		if(empty()){
			std::cout << "Queue is empty !" << std::endl;
		} else {
			std::cout << "Queue is not empty !" << std::endl;
		}
	}

	void print(){
		Node* temp;
		if((this-> head == NULL) && (this-> tail == NULL)){
			std::cout << "Queue is empty !" << std::endl;
		} else {
			temp = this-> head;
			std::cout<<"Queue elements are: ";
			while(temp != NULL){
				std::cout << " -> " << temp-> data; 
				temp = temp-> next;
			}
			std::cout << std::endl;
		}
	}
	
	~Queue() {
		while (this->head != NULL) {
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}

};

int main (){
	Queue q;
	q.isEmpty();
	std::cout << "Empty : " << q.empty() << std::endl;
	std::cout << "Size : " << q.getSize() << std::endl;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	q.print();
	q.push_back(4);
	q.push_back(5);
	q.print();
	q.pop_front();
	q.print();
	std::cout << "Front : " << q.front() << std::endl;
	std::cout << "Back : " << q.back() << std::endl;
	std::cout << "Size : " << q.getSize() << std::endl;

	return 0;
}
