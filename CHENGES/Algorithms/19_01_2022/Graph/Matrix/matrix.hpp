#include <iostream>

class Graph {
private:
	bool** matrix;
	int vertices;

public:	
	Graph(int vertices) {
		this->vertices = vertices;
		this->matrix = new bool*[vertices];

		for (int i = 0; i < vertices; ++i) {
			this->matrix[i] = new bool[vertices];
			for (int j = 0; j < vertices; ++j) {
				matrix[i][j] = false;
			}
		}
	}

	void addEdge(int i, int j) {
		this->matrix[i][j] = true;
	}

	void removeEdge(int i, int j) {
		this->matrix[i][j] = false;
	}

	void display() {
		std::cout << "    ";
		for (int i = 0; i < vertices; i++) {
			std::cout << i << " ";
		}
		std::cout << std::endl;

		for (int i = 0; i < vertices; i++) {
			std::cout << i << " : ";
			for (int j = 0; j < vertices; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	 ~Graph() {
		for (int i = 0; i < vertices; ++i) {
			delete[] this->matrix[i];
		}
		delete[] this->matrix;
	 }

};
