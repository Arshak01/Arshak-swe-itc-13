#include <iostream>
#include <climits>
#include "ford.h"

struct Graph* createGraph(int vertic, int edge) {
	Graph* graph = new Graph();
	graph->vertic = vertic;
	graph->edge = edge;
	graph->edges = new Edge[edge];
	return graph;
}

void print(int *arr, int size) {
	for(int i = 0; i < size; ++i) {
		std::cout << i << " ===> " << arr[i] << std::endl; 
	}
}

void BFord(struct Graph* graph, int start) {
	int vertic = graph->vertic;
	int edge = graph->edge;
	int arr[vertic];
	for(int i = 0; i < vertic; ++i) {
		arr[i] = INT_MAX;
	}
	arr[start] = 0;
	for(int i = 1; i <= vertic - 1; ++i) {
		for(int j = 0; j < edge; ++j) {
			int firstV = graph->edges[j].start;
			int lastV = graph->edges[j].end;
			int weight = graph->edges[j].weight;
			if(arr[start] != INT_MAX && arr[firstV] + weight < arr[lastV]) {
				arr[lastV] = arr[firstV] + weight;
			}
		}
	}
	for(int i = 0; i < edge; ++i) {
		int firstV = graph->edges[i].start;
		int lastV = graph->edges[i].end;
		int weight = graph->edges[i].weight;
		if(arr[start] != INT_MAX && arr[firstV] + weight < arr[lastV]) {
			arr[lastV] = arr[firstV] + weight;
			std::cout << "Negative cycle!!!" << std::endl;
			return;
    	}
	}
	print(arr,vertic);
	return;
}
