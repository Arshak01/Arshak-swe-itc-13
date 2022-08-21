#include <iostream>
#include <chrono>
#include "../Bellman_Ford/graph.hpp"
#include "../B_S_Construct/construct.hpp"

using namespace std::chrono;

void bellmanGraph() {
	std::cout << "*** Bellman-Ford Graph  ***" << std::endl;
	int V, E, S;

	std::cout << "Enter number of vertices in graph\n";
	std::cin >> V;

	std::cout<<"Enter number of edges in graph\n";
	std::cin >> E;

	std::cout << "Enter your start vertex number\n";
	std::cin >> S;

	struct Graph* graph = createGraph(V, E);

	for(int i=0; i < E; ++i) {
		std::cout << "\nEnter edge " << i+1 << " start, end, weight :\n";
		std::cin >> graph-> edge[i].start;
		std::cin >> graph-> edge[i].end;
		std::cin >> graph-> edge[i].weight;
	}

	std::cout << std::endl;
	auto startB = high_resolution_clock::now();
	bellmanFord(graph, S);
	auto stopB = high_resolution_clock::now();
	auto durationB = duration_cast<microseconds>(stopB - startB);
	std::cout << "Duration : " << durationB.count() << std::endl;
	std::cout << std::endl;
	
}


void construct() {
	int n;
	int result;
	std::cout << "*** Construct ***" << std::endl;
	std::cout << "Entry size of construct : "; 
	std::cin >> n ;
	std::cout << std::endl;

	auto startC = high_resolution_clock::now();
	result = buildingWays(n);
	std::cout << "Count of ways : " << n << " is " << result  << std::endl;
	auto stopC = high_resolution_clock::now();
	auto durationC = duration_cast<microseconds>(stopC - startC);
	std::cout << "Duration : " << durationC.count() << std::endl;
	std::cout << std::endl;

}

int  countTime() {
	
	construct();

	bellmanGraph();

	return 0;
}
