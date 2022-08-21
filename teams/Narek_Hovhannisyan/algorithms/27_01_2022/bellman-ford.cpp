#include <iostream>
#include <vector>
#include "bellman-ford.hpp"

Edge::Edge(int src, int dest, int weight) {
    this->source = src;
    this->destination = dest;
    this->weight = weight;
}

Graph::Graph(int v, int e) {
    this->verticesCount = v;
    this->edgesCount = e;
}

void Graph::addEdge(int src, int dest, int weight) {
    Edge e(src, dest, weight);
    this->edges.push_back(e);
}

std::vector<int> belmanFord(Graph g, int src) {
    std::vector<int> result(g.verticesCount, INT32_MAX);
    result[src] = 0;

    // a little optimization
    bool isNeededbreak;
    for (int i = 0; i < g.verticesCount - 1; i++) {
        isNeededbreak = true;
        for (int j = 0; j < g.edges.size(); j++) {
            int srcIndex = g.edges[j].source;
            int destIndex = g.edges[j].destination;
            int weight = g.edges[j].weight;

            if (result[srcIndex] != INT32_MAX 
                && result[destIndex] > result[srcIndex] + weight) {
                result[destIndex] = result[srcIndex] + weight;
                isNeededbreak = false;
            }
        }
        if (isNeededbreak) break;
    }

    //check if there is a loop
    for (int i = 0; i < g.verticesCount; i++) {
        int srcIndex = g.edges[i].source;
        int destIndex = g.edges[i].destination;
        int weight = g.edges[i].weight;

        if (result[srcIndex] != INT32_MAX 
        && result[srcIndex] + weight < result[destIndex]) {
            std::cout << "!!! the graph contains cycle with negative balance" << std::endl;
        }
    }

    return result;
}

void print(const std::vector<int> &v, int src) {
    std::cout << "src " << "     dest" << "      weight" << std::endl;
    for (int i = 0; i < v.size(); i++) {
        std::cout << src << "   ->   " << i << "    =    " << v[i] << std::endl;
    }
    std::cout << std::endl;
}