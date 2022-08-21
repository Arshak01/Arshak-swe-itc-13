struct Edge {
    int source;
    int dest;
    int weight;
};

struct Graph {
    int V;
    int E;
    struct Edge* edge;
};

struct Graph* createGraph(int, int);

void printArr(int, int);

void BellmanFord(struct Graph* graph, int);


