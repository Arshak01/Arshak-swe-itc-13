#include <iostream>

struct Node {
	int data;
	Node* next;

	Node(){
		this->data = 0;
		this->next = NULL;
	}
};

class Stack {
	Node* head; 
	int size;
	
public:
	Stack(){
		head = NULL;
		size = 0;
	}
	
	int getSize(){
		return  this->size;
	}

	void push(int value){
		Node* temp = new Node();
		temp-> data = value;

		if(head == NULL){
			this-> head = temp;
			temp-> next = NULL;
		} else {
			temp-> next = head;
			this-> head = temp;
		}
		size++;
	}

	void pop() {
		if(this-> head == NULL){
			std::cout << "Stack is empty !" << std::endl;
		}else{
			Node* temp = head;
			head = head-> next;
			delete(temp);
		}
		size--;
	}

	int top() {
		return head->data;
	}
	
	bool empty(){
		return this-> head == NULL;
	} 

	void isEmpty(){
		if(empty()){
			std::cout << "Stack is empty !" << std::endl;
		} else {
			std::cout << "Stack is not empty !" << std::endl;
		}
	}

	void print(){
		Node* temp;
		if(this->head == NULL){
			std::cout << "Stack is empty !" << std::endl;
		} else {
			temp = this->head;
			std::cout<<"Stack elements are: ";
			while(temp != NULL){
				std::cout << " -> " << temp-> data; 
				temp = temp-> next;
			}
			std::cout << std::endl;
		}
	}
	
	~Stack() {
		while (this->head != NULL) {
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int main (){
	Stack s;
	s.isEmpty();
	std::cout << "Empty : " << s.empty() << std::endl;
	std::cout << "Size : " << s.getSize() << std::endl;
	s.push(10);
	s.push(20);
	s.push(30);
	s.print();
	s.push(40);
	s.push(50);
	s.print();
	s.pop();
	s.print();
	std::cout << "Top : " << s.top() << std::endl;
	std::cout << "Size : " << s.getSize() << std::endl;

	return 0;
}
