#include <iostream>
#include <climits>
#include "BelmanFord.cpp"

int main() {
    int V = 5;
    int E = 7;
    struct Graph* graph = createGraph(V, E);
    graph->edge[0].source = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 6;
	graph->edge[1].source = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 7;
	graph->edge[2].source = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 8;
	graph->edge[3].source = 1;
	graph->edge[3].dest = 4;
	graph->edge[3].weight = -4;
	graph->edge[4].source = 1;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 5;
	graph->edge[5].source = 3;
	graph->edge[5].dest = 1;
	graph->edge[5].weight = -2;
	graph->edge[6].source = 2;
	graph->edge[6].dest = 3;
	graph->edge[6].weight = -3;
    BellmanFord(graph, 0);

    return 0;
}
