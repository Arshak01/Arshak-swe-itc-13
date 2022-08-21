#include <list>

struct Graph {
    int vertixCount;
    std::list<int>* adj;

    void printAllPathsUtil(int, int, bool[], int[], int&);

    Graph(int);

    void addEdge(int, int);

    void printAllPaths(int, int);
};