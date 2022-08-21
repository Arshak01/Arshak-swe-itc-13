#include <iostream>
#include "graph_and_expSearch.hpp"

Graph::Graph(int n){
    node = n;
    graph = new int*[n];
    for(int i = 0; i < n; ++i){
        graph[i] = new int[n];
        for (int j = 0; j < n; ++j){
            Graph::graph[i][j] = 0;
        }
    }
}

void Graph::addDirection(int i, int j, int num){
    Graph::graph[i][j] = num;
}

void Graph::print() {
	for (int i = 0; i < node; ++i) {
		std::cout << i << "  ";
		for (int j = 0; j < node; ++j) {
			std::cout << Graph::graph[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Graph::~Graph() {
	for (int i = 0; i < node; ++i) {
		delete[] Graph::graph[i];
	}
	delete [] Graph::graph;
}
