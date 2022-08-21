#include <iostream>
#include "buildings.hpp"
#include "bellman-ford.hpp"

int main() {
    int a1 = 1, a2 = 2, a3 = 3;
    std::cout << getBuildingPossibleArrangementsCount(a2) << std::endl;
    std::cout << getBuildingPossibleArrangementsCount(a1) << std::endl;
    std::cout << getBuildingPossibleArrangementsCount(a3) << std::endl;
    std::cout << std::endl;

    Graph g(7, 10);
    g.addEdge(0, 1, 6);
    g.addEdge(0, 2, 5);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 4, -1);
    g.addEdge(2, 1, -2);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 2, -2);
    g.addEdge(3, 5, -1);
    g.addEdge(4, 6, 3);
    g.addEdge(5, 6, 3);
    std::vector<int> res = belmanFord(g, 0);
    // if you want to change source vertex, please make sure that 
    // the rest of the vertices are reachable
    print(res, 0);

    Graph g2(4, 4);
    g2.addEdge(0, 1, 4);
    g2.addEdge(0, 3, 5);
    g2.addEdge(2, 1, -10);
    g2.addEdge(3, 2, 3);
    std::vector<int> res2 = belmanFord(g2, 0);
    print(res2, 0);

    Graph g3(4, 5);
    g3.addEdge(0, 1, 4);
    g3.addEdge(0, 3, 5);
    g3.addEdge(1, 3, 5);
    g3.addEdge(2, 1, -10);
    g3.addEdge(3, 2, 3);
    std::vector<int> res3 = belmanFord(g3, 0);
    print(res3, 0);

    return 0;
}
