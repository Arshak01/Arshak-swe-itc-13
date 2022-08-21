#include <iostream>
#include "graph_matrix.h"

GraphM::GraphM (int numVertics) {
	this->vertics = numVertics;
	addMatrix = new int*[numVertics];
	for(int i = 0; i < numVertics; ++i) {
		addMatrix[i] = new int[numVertics];
		for(int j = 0; j < numVertics; j++) {
			addMatrix[i][j]; 
		}
	}
}

GraphM::~GraphM() {
	for(int i = 0; i < this->vertics; ++i) {
		delete[] addMatrix[i];
	}
	delete[] addMatrix;
}

void GraphM::addEdge(int i, int j, int value) {
	addMatrix[i][j] = value;
}

void GraphM::print() {
	char arr[this->vertics] = {'A','B','C','D','E','F'};
	std::cout << "   ";
	for(int i = 0; i < this->vertics; ++i) {
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
	for(int i = 0; i < this->vertics; ++i) {
		std::cout << arr[i] << " ";
		for(int j = 0; j < this->vertics; ++j) {
			if(addMatrix[i][j] / 10 == 0) {
				std::cout << " " << addMatrix[i][j] << " ";
			}
			else {
				std::cout << addMatrix[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
}
