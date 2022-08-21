#include <iostream>
#include "GraphHeader.hpp"
int main(){
Graph graph(5);
	graph.addEdge(0, 1);
	graph.addEdge(0, 3);
	graph.addEdge(0, 4);
	graph.addEdge(1, 0);
	graph.addEdge(1, 2);
	graph.addEdge(2, 1);
	graph.addEdge(2, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 2);
	graph.addEdge(3, 0);
	graph.addEdge(3, 4);
	graph.addEdge(4, 0);
	graph.addEdge(4, 2);
	graph.addEdge(4, 3);
	graph.BFS(0);
	graph.DFS(0);
	std::cout<<std::endl;
	std::cout << "Paths from 0 to 4";
	graph.printPaths(0, 4);

}
