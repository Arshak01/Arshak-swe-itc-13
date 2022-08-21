#include <iostream>
#include "graph_hmap.h"

Node::Node() {
	this->vertic = 0;
	this->weight = 0;
	this->next = NULL;
}

Graph::Graph(Edge edges[], int size, int vertics) {
	head = new Node*[vertics]();
	this->vertics = vertics;
	for (int i = 0; i < vertics; ++i) {
		head[i] = NULL;
	}
	for (int i = 0; i < size; ++i) {
		int start_ver = edges[i].start_ver;
		int end_ver = edges[i].end_ver;
		int weight = edges[i].weight;
		Node* newNode = adjListNode(end_ver, weight, head[start_ver]);
		head[start_ver] = newNode;
	}
}

Graph::~Graph() {
	for (int i = 0; i < vertics; ++i) {
		delete[] head[i];
	}
	delete[] head;
}
	
int Graph::graphVertics() {
	std::cout << "Choose head to see info : ";
	char symbol;
	int vertic;
	std::cin >> symbol;
	while(symbol != 'A' && symbol != 'B' && symbol != 'C' && symbol != 'D' && symbol != 'E' && symbol != 'F') {
		std::cout << "Wrong input, try again!!! ";
		std::cin >> symbol;
	}
	switch(symbol) {
		case 'A': 
			vertic = 0;
			return vertic;
		case 'B': 
			vertic = 1;
			return vertic;
		case 'C': 
			vertic = 2;
			return vertic;
		case 'D': 
			vertic = 3;
			return vertic;
		case 'E': 
			vertic = 4;
			return vertic;
		case 'F': 
			vertic = 5;
			return vertic;
	}
	return 0;
}

Node* Graph::adjListNode(int vertic, int weight, Node* head) {
	Node* newNode;
	if(top == NULL) {
		newNode = new Node();
		newNode->vertic = vertic;
		newNode->weight = weight;
		top = newNode;
		newNode->next = NULL;
		return newNode;
	}
	else {
	Node* temp = top;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	newNode->vertic = vertic;
	newNode->weight = weight;
	temp->next = newNode;
	newNode->next = NULL;
	}
	return newNode;
}

void Graph::printList(Node* ptr, int i, char* arr) {
	Node* temp = ptr;
	while (temp != NULL) {
		std::cout << arr[temp->vertic] << "(" << temp->weight << ") ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

void Graph::printHead(Node* ptr, char* arr) {
	while (ptr != NULL) {
		std::cout << arr[ptr->vertic] << "(" << ptr->weight << ") ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}
