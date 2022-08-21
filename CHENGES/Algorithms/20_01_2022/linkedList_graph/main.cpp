#include <iostream>
#include <limits.h>
#include "./DFS_BFS/graph.hpp"
#include "./HelloWorld.hpp"

int main() {
	printHello();	
	Graph *g = new Graph(6);
	
	g->addEdge(0, 1, 3);
	g->addEdge(0, 2, 15);
	g->addEdge(1, 2, 11);
	g->addEdge(1, 3, 8);
	g->addEdge(2, 3, 1);
	g->addEdge(2, 5, 4);
	g->addEdge(3, 4, 2);
	g->addEdge(4, 5, 8);

	g->printGraph();
	g->printWeight();
	g->minWeightCycle();	
	g->printDFS(5);
	g->bfs(0);

	return 0;
}
