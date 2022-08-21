#include <vector>

struct Edge {
    unsigned int source;
    unsigned int destination;
    int weight;

    Edge(int, int, int);
};

struct Graph {
    int verticesCount;
    int edgesCount;
    std::vector<Edge> edges;

    Graph(int, int);

    void addEdge(int src, int dest, int weight);
};

std::vector<int> belmanFord(Graph, int);

void print(const std::vector<int> &, int);
