#include <iostream>
#include "graph.h"

int main() {
	std::cout << "Hello World!!!" << std::endl;
	std::cout << "===============" << std ::endl;
	Graph graph(5);
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(2, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 4);
	graph.printPaths(0, 4);
	graph.DFS(0);
	graph.BFS(0);

  return 0;
}
