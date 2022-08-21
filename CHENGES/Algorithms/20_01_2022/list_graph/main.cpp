#include "./graph.hpp"
#include "./HelloWorld.hpp"

int main() {
	printHello();
	Graph g(6);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	
	g.printPaths(0, 4);
	g.DFS(2);
	g.BFS(0);

  return 0;
}
