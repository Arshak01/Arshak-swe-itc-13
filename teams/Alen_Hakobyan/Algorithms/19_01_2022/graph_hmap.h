#ifndef GRAPH_HMAP_H
#define GRAPH_HMAP_H

class Node {
public:
	int vertic, weight;
	Node* next;
	Node();
};

class Edge {
public:
	int start_ver, end_ver, weight;
};

class Graph {
public:
	Node* top;
	int vertics;
	Node** head;
	Graph(Edge edges[], int size, int vertics);
	~Graph();
	int graphVertics();
	Node* adjListNode(int vertics, int weight, Node* head);
	void printList(Node* ptr, int i, char* arr);
	void printHead(Node* ptr, char* arr);
};

#endif
