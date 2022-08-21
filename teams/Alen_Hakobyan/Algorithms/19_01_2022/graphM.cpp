#include <iostream>
#include "graph_matrix.h"

int main() {
	GraphM gm(6);
	gm.addEdge(0,1,7);
	gm.addEdge(0,2,12);
	gm.addEdge(1,2,2);
	gm.addEdge(1,3,9);
	gm.addEdge(2,4,10);
	gm.addEdge(3,5,1);
	gm.addEdge(4,3,4);
	gm.addEdge(4,5,5);
	gm.print();

	return 0;
}
