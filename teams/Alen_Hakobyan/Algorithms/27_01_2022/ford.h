#ifndef FORD_H
#define FORD_H

struct Edge {
	int start, end, weight;
};

struct Graph {
	int vertic, edge;
	Edge* edges;
};

struct Graph* createGraph(int vertic, int edge);
void BFord(struct Graph* graph, int start);
void print(int *arr, int size);

#endif
