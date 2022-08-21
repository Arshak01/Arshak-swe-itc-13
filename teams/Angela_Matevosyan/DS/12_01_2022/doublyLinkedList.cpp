#include <iostream>

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int value) {
		data = value;
	}
};

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int size;
public:
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	DoublyLinkedList(const DoublyLinkedList& dll) {
		Node* temp = dll.head;
		while (temp != NULL) {
			pushFront(temp->data);
			temp = temp->next;
		}
	}

	void pushBack(int data) {
		Node* node = new Node(data);
		if (tail == NULL)
			head = node;
		else {
			node->prev = tail;
			tail->next = node;
		}
		tail = node;
		++size;
	}

	void pushFront(int data) {
		Node* node = new Node(data);
		if (head == NULL)
			tail = node;
		else {
			node->next = head;
			head->prev = node;
		}
		head = node;
		++size;
	}

	void popBack() {
		if (head != NULL) {
			if (head->next == NULL) {
				head = NULL;
			}
			else {
				Node* temp = head;
				while (temp->next->next != NULL)
					temp = temp->next;
				Node* lastNode = temp->next;
				temp->next = NULL;
				free(lastNode);
			}
		}
	}

	void popFront() {
		if (head != NULL) {
			Node* temp = head;
			head = head->next;
			free(temp);
			if (head != NULL)
				head->prev = NULL;
		}
	}

	void insert(int position, int data) {
		Node* newNode = new Node(data);
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;

		if (position < 1)
			std::cout << "\nPosition should be >= 1.";
		else if (position == 1) {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		else {
			Node* temp = head;
			for (int i = 1; i < position - 1; ++i) {
				if (temp != NULL)
					temp = temp->next;
			}

			if (temp != NULL) {
				newNode->next = temp->next;
				newNode->prev = temp;
				temp->next = newNode;
				if (newNode->next != NULL)
					newNode->next->prev = newNode;
			}
			else
				std::cout << "\nThe previous node is null.";
		}
	}
	
	void remove(int data) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == data) {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			temp = temp->prev;
		}
		std::cout << "There is no such data in the list\n";
	}

	void print() {
		Node* temp;
		if (head == NULL)
			std::cout << "There is an empty list." << std::endl;
		else {
			temp = head;
			while (temp != NULL) {
				std::cout << temp->data << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
	}

};

int main() {
	DoublyLinkedList dll;
	dll.pushBack(2);
	dll.pushBack(4);
	dll.pushFront(6);
	dll.pushFront(8);
	dll.popFront();
	dll.popBack();
	dll.insert(1, 5);
	dll.remove(2);	
	std::cout << "Doubly Linked List1: ";
	dll.print();
	DoublyLinkedList dll2 = dll;
	dll2.pushBack(10);
	std::cout << "Doubly Linked List2: ";
	dll2.print();
	return 0;

}
