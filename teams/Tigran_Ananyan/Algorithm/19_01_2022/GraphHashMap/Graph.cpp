#include <iostream>
#include <vector>
#include "Graph.hpp"

void addEdge(std::vector <std::pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(std::make_pair(v, wt));
    adj[v].push_back(std::make_pair(u, wt));
}

void printGraph(std::vector<std::pair<int,int> > adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        std::cout << "Node " << u << " makes an edge with" << std::endl;
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            std::cout << "\tNode " << v << " with edge weight = "
                 << w << std::endl;
        }
        std::cout << std::endl;
    }
}
