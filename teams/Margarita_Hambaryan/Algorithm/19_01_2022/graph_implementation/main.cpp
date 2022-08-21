#include <iostream>
#include "graphImplementation.hpp"

int main() {
    GraphImplementation graph(6);
    graph.addEdge(0, 1, 7); 
    graph.addEdge(0, 2, 8); 
    graph.addEdge(1, 2, 9); 
    graph.addEdge(1, 3, 2); 
    graph.addEdge(2, 4, 6); 
    graph.addEdge(3, 5, 1); 
    graph.addEdge(4, 3, 4); 
    graph.addEdge(4, 5, 5); 
    graph.print();
    return 0;
}
