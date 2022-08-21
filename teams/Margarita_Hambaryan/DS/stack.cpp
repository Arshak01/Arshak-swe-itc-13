#include <iostream>

class Node {
	public:
		int data;
		Node* next;
};

class Stack {
	private:
		Node* head;
		int m_size;
	public:
		Stack() {
			this -> head = NULL;
			m_size = 0;
		}
		

		void pop() {
			if (m_size == 0) {
				std::cout << "Stack is empty. You can't use pop method.\n";
			}
			--m_size;
			Node *temp = this -> head;
			this -> head = temp -> next;
			delete temp;
			std::cout << "Stack is popped.\n";
		}
		
		void push(int val) {
			++m_size;
			Node *temp = new Node;
			temp -> data = val;
			temp -> next = this -> head;
			this -> head = temp;
			temp = NULL;
			std::cout << val << " added to stack." << "\n";
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
		
		int top() {
			return this -> head -> data;
		}
		
		~Stack() {
			delete this -> head;
		}
};

int main() {
	Stack s;
	s.push(4);
	s.push(5);
	s.push(17);
	s.pop();
	std::cout << "The top element is " << s.top() << "\n";
	std::cout << s.empty() << "\n";
	std::cout << "Size of stack is equal to " << s.size() << "\n";
	s.push(12);
	std::cout << "Size of stack is equal to " << s.size() << "\n";

	return 0;
}



