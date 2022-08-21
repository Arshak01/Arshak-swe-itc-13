#include <iostream>
#include "GraphMatrix/graphMatrix.h"
#include "GraphHashMap/graphHashMap.h"

int main() {

    Graph graphSecond(6);

    graphSecond.addLink(0, 1, 7);
    graphSecond.addLink(0, 2, 12);
    graphSecond.addLink(1, 2, 2);
    graphSecond.addLink(1, 3, 9);
    graphSecond.addLink(2, 4, 10);
    graphSecond.addLink(3, 5, 1);
    graphSecond.addLink(4, 3, 4);
    graphSecond.addLink(4, 5, 5);
    
    std::cout << "The Graph presented by Matrix." << std::endl;
    graphSecond.printMatrix();

    GraphHashMap graphFirst;

    graphFirst.addEdge("A", "B", 7);
    graphFirst.addEdge("A", "C", 12);
    graphFirst.addEdge("B", "D", 9);
    graphFirst.addEdge("B", "C", 2);
    graphFirst.addEdge("C", "E", 10);
    graphFirst.addEdge("E", "D", 4);
    graphFirst.addEdge("E", "F", 5);
    graphFirst.addEdge("D", "F", 1);
    
    std::cout << "The Graph presented by HashMap." << std::endl;
    graphFirst.printGraph();

    return 0;
}
