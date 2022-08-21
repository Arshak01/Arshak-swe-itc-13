#include <iostream>
#include <limits.h>
 
 
struct Edge {
	int start; 
	int end;
	int	weight;
	
};
 
struct Graph {
	int V;
	int	E;
	struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E) {
	
	struct Graph* graph = new Graph();
	graph->V = V; 
	graph->E = E;
	graph->edge = new Edge();

    return graph;
}
 
void result(int dist[], int n) {
	
	std::cout<<"\nVertic\tDistance from Source Vertic\n";
	int i;
 
	for (i = 0; i < n; ++i) {
		std::cout << i << "\t\t" << dist[i] << std::endl;;
	}
}
 
void bellmanFord(struct Graph* graph, int start) {
	int V = graph->V;
	int E = graph->E;
	int distance[V];
	int i,j;
 
	for (i = 0; i < V; ++i) {
		distance[i] = INT_MAX;
	}
    distance[start] = 0;
 
	for (i = 1; i <= V-1; ++i) {
		for (j = 0; j < E; ++j) {
			int u = graph->edge[j].start;
			int v = graph->edge[j].end;
			int weight = graph->edge[j].weight;

			if (distance[u] + weight < distance[v]) {
				distance[v] = distance[u] + weight;
			}
		}
	}
 
	for (i = 0; i < E; ++i) {
		int u = graph->edge[i].start;
		int v = graph->edge[i].end;
		int weight = graph->edge[i].weight;
 
		if (distance[u] + weight < distance[v]) {
				std::cout<<"\nGraph contains negative edge cycle\n";
		}
	}
 
	result(distance, V);
 
	return;
}
 
