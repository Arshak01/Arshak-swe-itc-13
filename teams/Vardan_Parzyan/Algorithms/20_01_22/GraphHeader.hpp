#include <list>

class Graph {
	int vertic;
	std::list<int>* adjLists;
	bool* visited;

public:
	Graph(int vertices);
	void addEdge(int source, int destination);
	void printPaths(int, int);
	void printPathsRec(int start, int end, bool visited[], int path[], int& index);
	void DFS(int vertex);
	void BFS(int vertex);
	void DFSRecursion(int vertex);

};
