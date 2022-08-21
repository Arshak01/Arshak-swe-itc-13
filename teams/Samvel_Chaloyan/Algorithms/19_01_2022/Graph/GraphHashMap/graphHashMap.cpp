#include <iostream>
#include <unordered_map>
#include <list>
#include "graphHashMap.h"

void GraphHashMap::addEdge(std::string src, std::string des, int weight) {
    l[src].push_back(make_pair(des, weight));
}

void GraphHashMap::printGraph() {

    for (auto vertex:l) {
        std::string currentVertex = vertex.first;
        std::list < std::pair < std::string, int > > neighbor = vertex.second;

        std::cout << currentVertex << " -> ";

        for (auto each:neighbor) {
            std::string des = each.first;
            int weight = each.second;
            std::cout << des << ":" << weight << " ";
        }
        std::cout << std::endl;
    }
}
