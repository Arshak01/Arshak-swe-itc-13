int min(int, int);
int binSearch(int*, int, int, int);
int expSearch(int*, int, int);
void print(int*, int, int);


class Graph{
	int** graph;
	int node;

public: 
	Graph(int node);
	void addDirection(int i, int j, int num);
	void print();
	~Graph();
};
