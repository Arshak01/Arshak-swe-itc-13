#include "dfs.hpp"
#include <iostream>

Graph::Graph(int v) {
    this->vertixCount = v;
    adj = new std::list<int>[this->vertixCount];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::printAllPaths(int src, int dst) {
    bool* visited = new bool[this->vertixCount];

    int* path = new int[this->vertixCount];
    int pathIndex = 0;

    for (int i = 0; i < vertixCount; i++) {
        visited[i] = false;
    }

    printAllPathsUtil(src, dst, visited, path, pathIndex);
}

void Graph::printAllPathsUtil(int u, int dst, bool visited[], int path[], int& pathIndex) {
    visited[u] = true;
    path[pathIndex] = u;
    pathIndex++;

    if (u == dst) {
        for (int i = 0; i < pathIndex; i++) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++) {
            if (!visited[*i]) {
                printAllPathsUtil(*i, dst, visited, path, pathIndex);
            }
        }
    }
    pathIndex--;
    visited[u] = false;
}