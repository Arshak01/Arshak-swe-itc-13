#include <iostream>
#include "graphMatrix.h"

//class Graph {
//    private:
//        int** matrix;
//        int numberNode;
//    public:
//        Graph(int);
//        ~Graph();
//        void printMatrix();
//        void addLink(int, int, int);
//            
//};

Graph::Graph(int node) {
    this -> numberNode = node;
    matrix = new int*[numberNode];

    for (int i = 0; i < numberNode; ++i) {
        matrix[i] = new int[numberNode];
        for (int j = 0; j < numberNode; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < numberNode; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Graph::printMatrix() {
        std::cout << "    ";
    for (char k = 'A'; k < 'A' + numberNode; ++k) {
        std::cout << k << "  ";
    }
    std::cout << std::endl;
    for (char k = 'A', i = 0; i < 0 + numberNode && k < 'A' + numberNode; ++k, ++i) {
        std::cout << k << " : ";
        for (int j = 0; j < numberNode; ++j) {
            std::cout << matrix[i][j] << "  ";
        } 
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Graph::addLink(int row, int column, int weight) {
    this -> matrix[row][column] = weight;
}
