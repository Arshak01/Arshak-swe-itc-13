#include <iostream>
using namespace std;


class Node {

public:
	int data;
	Node* link;
	
};

class Stack {

public:

	int stackSize = 0;
	Node* head = NULL;
	
	Stack () {}
    
	void push (int value) {
    		if(head == NULL){
    			head = new Node();
    		} else {
        		Node *ptr = new Node();
        		ptr->data = value;
        		ptr->link = head;
        		head = ptr;
        		this->stackSize++;
        	}
    	}
    
    	void pop() {
        	if (empty()) {
            		cout << "Stack is Empty" << endl;
		} else {
           		 Node *ptr = head;
            		head = head -> link;
            		this->stackSize--;
            		delete(ptr);
		}
    	}
    
	bool empty() {
		if (head == NULL) {
        		//cout<<"is empty"<< endl;
		return true;
		} else {
			//cout<< "is not empty" << endl;
            	return false;
        	}
	}
    
	int size() {
		return this->stackSize+1;
    	}
    
	void top() {
        	if (empty()) {
 			cout << "Stack is empty : "<< endl;
        	} else {
            		cout << "Top element is : " << head-> data << endl;
        	}
    	}
    	
    	~Stack() {
		delete this->head;
		this->head = nullptr;
	}
};


int main() {
	Stack s;
	cout << "Stack pushing :";
	for(int i = 0; i < 5; i++ ) {
    		s.push(i);
    		cout << "\t" << i;
    	}
	cout << endl;
    	cout << "Stack size is : "<<s.size() << endl;
    	s.top();
    	cout << "Calling pop() " << endl;
    	s.pop();
    	cout << "Stack size is : "<<s.size() << endl;
    	s.top();
    	if(s.empty()){
    		cout << "Stack Is empty" << endl;
    	} else {
    		cout << "Is not empty" << endl;
    	}
    	
    return 0;
}
