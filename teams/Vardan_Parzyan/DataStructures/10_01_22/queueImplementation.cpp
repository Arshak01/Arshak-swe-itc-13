#include <iostream>
using namespace std;
class Node {
private:
	Node *prev;
	int num;

public:
	Node() {
		this -> num = 0;
		this -> prev = nullptr;
	}

	Node(int num, Node *prev) {
		this -> num = num;
		this -> prev = prev;
	}

	int getNum() const {
		return this -> num;
	}

	void setNum(int num) {
		this  ->num = num;
	}

	Node* getPrev() const {
		return this -> prev;
	}

	void setPrev(Node *prev) {
		this -> prev = prev;
	}
};

class Queue {

private:
	int length = 0;
	Node *tail = nullptr;
	Node *head = nullptr;

public:
	Queue() {
		
	}

	void popFront() {
		if(isEmpty()) {
			return;
		}
		Node *temp = head;
		head = head -> getPrev();
		temp -> setNum(0);
		delete temp;
		temp = nullptr;
		length--;
	}

	void pushBack(int value) {
		Node *temp = new Node;
		temp -> setNum(value);
		temp -> setPrev(nullptr);
		if(this->isEmpty()) {
			head = temp;
			tail = temp;
		} else {
			tail -> setPrev(temp);
			tail = temp;
		}
		length++;
	}

	int size() const {
		return  length;
	}

	bool isEmpty() const {
		if(length == 0) {
			return true;
		} else {
			return false;
		}
	}

	int front() const {
		if(isEmpty()) {
			return 0;
		}
		return this -> head -> getNum();
	}

	int back() const {
		if(isEmpty()) {
			return 0;
		}
		return this -> tail -> getNum();
	}

	~Queue() {
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
	}

};

int main() {
	Queue q;
	cout << "Pushing elements ";
	for(int i = 0; i < 5; i++){
		q.pushBack(i*10);
		cout << "\t" << (i*10);
		cout << "\t";
	}
	cout << endl;
	cout << "Queue size is : " << q.size() << endl;
	cout << "Front element is :  " << q.front() << endl;
	cout << "Calling Pop()" << endl;
	q.popFront();
	cout << "After pop() front element is :  " << q.front() << endl;
	cout << "Queue size is : " << q.size() << endl;
	
	cout << "Back element is : " << q.back() << endl;
	cout << "Pushing element : '99'" << endl;
	q.pushBack(99);
	cout << "After pushing back element is :  " << q.back() << endl;
	cout << "Queue size is : " << q.size() << endl;
	
	
	return 0;
}
