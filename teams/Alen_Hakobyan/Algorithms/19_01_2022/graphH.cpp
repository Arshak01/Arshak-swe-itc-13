#include <iostream>
#include "graph_hmap.h"

int main() {
	Edge edges[] ={
		{0,1, 7},
		{0,2,12},
		{1,2, 2},
		{1,3, 9},
		{2,4,10},
		{3,5, 1},
		{4,3, 4},
		{4,5, 5}
	};
	char arr[] = {'A','B','C','D','E','F'};
	int vertics = 6;
	int size = sizeof(edges)/sizeof(edges[0]);
	Graph graph(edges, size, vertics);
	for (int i = 0; i < vertics; i++) {
		std::cout << arr[i] << " ";
		graph.printList(graph.head[i], i, arr);
	}
	graph.printHead(graph.head[graph.graphVertics()], arr);

	return 0;
}
