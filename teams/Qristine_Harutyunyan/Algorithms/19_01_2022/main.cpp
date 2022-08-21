#include <iostream>
#include <chrono>
#include "graph_and_expSearch.hpp"



int main() {
	int arr[] = {2, 5, 8, 9, 12, 15, 19, 35, 45, 64};
	int size = sizeof(arr)/sizeof(arr[0]);
	print(arr, size, 19);
	std::cout << std::endl;

	Graph g(6);
	g.addDirection(0, 1, 7);
	g.addDirection(0, 2, 12);
	g.addDirection(1, 2, 2);
	g.addDirection(1, 3, 9);
	g.addDirection(2, 4, 10);
	g.addDirection(3, 5, 1);
	g.addDirection(4, 3, 4);
	g.addDirection(4, 5, 5);
	g.print();	

    return 0;
}
