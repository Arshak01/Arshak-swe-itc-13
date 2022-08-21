#include <iostream>
#include <vector>
#include "Graph.hpp"

int main()
{
    int V = 6;
    std::vector<std::pair<int, int> > adj[V];
    addEdge(adj, 0, 1, 7);
    addEdge(adj, 0, 2, 12);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 1, 3, 9);
    addEdge(adj, 2, 4, 10);
    addEdge(adj, 3, 5, 1);
    addEdge(adj, 4, 3, 4);
    addEdge(adj, 4, 5, 5);
    printGraph(adj, V);
    return 0;
}
