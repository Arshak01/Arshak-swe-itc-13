#include <iostream>
#include "GraphHeader.hpp"

Graph::Graph(int vertices) {
	this->vertic = vertices;
	this->adjLists = new std::list<int>[vertices];
	this->visited = new bool[vertices];
}

void Graph::addEdge(int source, int destination) {
	this->adjLists[source].push_front(destination);
}

void Graph::printPaths(int start, int end) {
	bool* visited = new bool[this->vertic];
	int* path = new int[this->vertic];
	int index = 0;
	std::cout << std::endl;
	for (int i = 0; i < this->vertic; ++i) {
		visited[i] = false;
	}    
	printPathsRec(start, end, visited, path, index);
	std::cout << std::endl;
}

void Graph::printPathsRec(int start, int end, bool visited[], int path[], int& index) {
	visited[start] = true;
	path[index] = start;
	index++;
	if (start == end) {
		for (int i = 0; i < index; ++i) {
			std::cout << path[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::list<int>::iterator i;
		for (i = adjLists[start].begin(); i != adjLists[start].end(); ++i) {
			if (!visited[*i]) {
				printPathsRec(*i, end, visited, path, index);
			}
		}
	}
	index--;
	visited[start] = false;
}

void Graph::DFSRecursion(int vertic) {
	visited[vertic] = true;
	std::list<int> adjList = adjLists[vertic];
	std::cout << vertic << " ";
	std::list<int>::iterator i;
	for (i = adjList.begin(); i != adjList.end(); ++i) {
		if (!visited[*i]){
			DFSRecursion(*i);
		}
	}
}

void Graph::DFS(int vertic) {
	std::cout << " DFS :: " ;
	DFSRecursion(vertic);
	std::cout << std::endl;
}

void Graph::BFS(int start_ver) {
	bool* visited = new bool[this->vertic];
	for(int i = 0; i < this->vertic; ++i) {
		visited[i] = false;
	} 
	std::list<int> queue;
	visited[start_ver] = true;
	queue.push_back(start_ver);
	std::list<int>::iterator i;
 	std::cout << " BFS :: " ;
	while(!queue.empty()) {
		start_ver = queue.front();
		std::cout << start_ver << " ";
		queue.pop_front();
		for (i = adjLists[start_ver].begin(); i != adjLists[start_ver].end(); ++i) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	std::cout << std::endl;
}
