#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

class GraphM {
private:
	int vertics;
	int** addMatrix;
public:
	GraphM (int numVertics);
	~GraphM();
	void addEdge(int i, int j, int value);
	void print();
};

#endif
