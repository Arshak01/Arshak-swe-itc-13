#include <iostream>
#include <vector>
#include "bfs.hpp"
#include "dfs.hpp"

int main() {
    std::cout << "Hello world" << std::endl;
    std::vector<std::vector<int>> graph;
    int vertix = 5;
    graph.resize(vertix);

    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[0].push_back(4);

    graph[1].push_back(0);
    graph[1].push_back(2);

    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);

    graph[3].push_back(0);
    graph[3].push_back(2);
    graph[3].push_back(4);

    graph[4].push_back(0);
    graph[4].push_back(2);
    graph[4].push_back(3);

    int src = 0;
    int dst = 4;

    std::cout << "Breadth First Search" << std::endl;
    std::cout << "all paths from " << src << " to ";
    std::cout << dst << std::endl;
    findPathsUsingBFS(graph, src, dst);
    std::cout << std::endl;

    std::cout << "Depth First Search" << std::endl;
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 4);

    g.addEdge(1, 0);
    g.addEdge(1, 2);

    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.addEdge(3, 0);
    g.addEdge(3, 2);
    g.addEdge(3, 4);

    g.addEdge(4, 0);
    g.addEdge(4, 2);
    g.addEdge(4, 3);

    int src2 = 0;
    int dst2 = 4;

    std::cout << "all paths from " << src2 << " to ";
    std::cout << dst2 << std::endl;
    g.printAllPaths(src2, dst2);
   
    return 0;
}
