#include <iostream>

class GraphMatrix {

public:
	bool **matrix;
	int vertices;

	GraphMatrix(int vertices) {
		this->vertices = vertices;
		matrix = new bool *[vertices];
		for (int i = 0; i < vertices; i++) {
			matrix[i] = new bool[vertices];
			for (int j = 0; j < vertices; j++) {
				matrix[i][j] = false;
			}
		}
	}

	void fillMatrix(int i, int j) {
		matrix[i][j] = true;
	}

	void print() {
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
			std::cout << "\n";
		}
	}

	~GraphMatrix() {
		for (int i = 0; i < vertices; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
};

int main() {
	GraphMatrix matrix(6);
	matrix.fillMatrix(0, 1);
	matrix.fillMatrix(0, 2);
	matrix.fillMatrix(1, 2);
	matrix.fillMatrix(1, 3);
	matrix.fillMatrix(2, 4);
	matrix.fillMatrix(3, 5);
	matrix.fillMatrix(4, 3);
	matrix.fillMatrix(4, 5);
	matrix.print();

	return 0;
}
