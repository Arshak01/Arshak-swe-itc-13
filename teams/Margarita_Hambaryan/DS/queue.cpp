#include <iostream>

class Node {
	public:
		int data;
		Node* next;
		Node(int data) {
			this -> data = data;
			this -> next = nullptr;
		}
};

class Queue {
	private:
		Node* head;
		Node* tail;
		int m_size;
	
	public:
		Queue() {
			m_size = 0;
			this -> head = NULL;
			this -> tail = NULL;
		}
		
		void pop_front() {
			if (m_size == 0) {
				std::cout << "Queue is empty so you can't use pop_front() method.\n";
			}
			--m_size;	
			Node* temp = this -> head;
			this -> head = temp -> next;
			temp -> data = 0;
			delete temp;
			std::cout << "Queue is popped.\n";        
		}

        void push_back(int val) {
            ++m_size;
            Node *temp = new Node(val);
			if (this -> tail = nullptr) {
				this -> head = this -> tail = temp;
				return;
			}
            this -> tail -> next = temp;
            this -> tail = temp;
            std::cout << val << " added to queue." << "\n";
        }

		int size() {
			return m_size;
		}
		
        bool empty() {
            if (m_size == 0) {
                std::cout << "Stack is empty.\n";
                return true;
            }
            std::cout << "Stack is NOT empty.\n";
            return false;
        }
		
		/*
		int front() {
			return this -> head;
		}

		int back() {
			return this -> *tail;
		}
		*/
		
		~Queue() {
			delete this -> head;
			delete this -> tail;
		}
};

int main() {
	Queue q;
	q.push_back(10);
	q.push_back(17);
	q.push_back(9);
	q.push_back(8);
	
//	std::cout << "The first element is " << q.front() << "\n";
//	std::cout << "The last element is " << q.back() << "\n";
	q.empty();
	std::cout << "The length of queue is " << q.size() << "\n";
	q.pop_front();
	std::cout << "The length of queue is " << q.size() << "\n";
//	std::cout << "The first element is " << q.front() << "\n";

	return 0;
} 







