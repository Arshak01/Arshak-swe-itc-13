#include "graphImplementation.hpp"
#include <iostream>

GraphImplementation::GraphImplementation(int vertices) {
	this -> vertices = vertices;
	matrix = new int*[vertices];
	
	for (int i = 0; i < vertices; ++i) {
		matrix[i] = new int[vertices];
		for (int j = 0; j < vertices; ++j) {
			matrix[i][j] = 0;
			}
		}
	}
		
void GraphImplementation::addEdge(int i, int j, int weight) {
	matrix[i][j] = weight;
}

void GraphImplementation::print() {
	std::cout << "    ";
	for (int i = 0; i < this -> vertices; ++i) {
		std::cout << i << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < this -> vertices; i++) {
		std::cout << i << " : ";
		for (int j = 0; j < this -> vertices; j++) {
			std::cout << this -> matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}
