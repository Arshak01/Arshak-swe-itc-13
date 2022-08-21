#include <iostream>
#include "ford.h"

int main() {
	int vertic = 5;
	int edge = 10;
	int startV = 0;
	Graph* graph = createGraph(vertic,edge);
	graph->edges[0].start = 0;
	graph->edges[0].end = 1;
	graph->edges[0].weight = 6;

	graph->edges[1].start = 0;
	graph->edges[1].end = 2;
	graph->edges[1].weight = 7;

	graph->edges[2].start = 1;
	graph->edges[2].end = 2;
	graph->edges[2].weight = 8;

	graph->edges[3].start = 1;
	graph->edges[3].end = 4;
	graph->edges[3].weight = -4;
	
	graph->edges[4].start = 1;
	graph->edges[4].end = 3;
	graph->edges[4].weight = 5;
	
	graph->edges[5].start = 3;
	graph->edges[5].end = 1;
	graph->edges[5].weight = -2;

	graph->edges[6].start = 2;
	graph->edges[6].end = 3;
	graph->edges[6].weight = -3;

	graph->edges[7].start = 2;
	graph->edges[7].end = 4;
	graph->edges[7].weight = 9;

	graph->edges[8].start = 4;
	graph->edges[8].end = 0;
	graph->edges[8].weight = 2;

	graph->edges[9].start = 4;
	graph->edges[9].end = 3;
	graph->edges[9].weight = 7;
	BFord(graph, startV);

	return 0;
}
