#include <iostream>
#include <limits.h>
#include <queue>
#include "./edge.hpp"
#include "./vertic.hpp"

class Graph {
public:
	int size;
	int result;
	Vertices* vertic;
	
	Graph(int size) {
		this->size = size;
		this->result = 0;
		this->vertic = new Vertices[size];
		this->setData();
	}

	void setData() {
		if (this->size <= 0) {
				std::cout << "\nEmpty Graph" << std::endl;
		} else {
			for (int i = 0; i < this->size; ++i) {
				this->vertic[i].data = i;
			}
		}
	}

	void connection(int start, int end, int weight) {
		Edge* edge = new Edge(end, weight);
		
		if (this->vertic[start].start == NULL) {
			this->vertic[start].start = edge;
		} else {
			this->vertic[start].end->start = edge;
		}
		this->vertic[start].end = edge;
	}

	void addEdge(int start, int end, int weight) {
		this->connection(start, end, weight);
		this->connection(end, start, weight); // if we want to graph well be direct or undirect
	}

	void printGraph() {
		std::cout << " **** Vertic Edge **** ";
		if (this->size > 0) {
			for (int i = 0; i < this->size; ++i) {
				std::cout << "\nVertex " << i << " : ";
				Edge* edge = this->vertic[i].start;
				while (edge != NULL) {
					std::cout << "  " << this->vertic[edge->name].data;
					edge = edge->start;
				}
			}
		}
		std::cout << "\n" << std::endl;
	}
	
	void printWeight() {
		std::cout << " **** Vertic Weight **** ";
		if (this->size > 0) {
			for (int i = 0; i < this->size; ++i) {
				std::cout << "\nVertex " << i << " : ";
				Edge* edge = this->vertic[i].start;
				while (edge != NULL) {
					std::cout << " " << edge->weight << "  ";
					edge = edge->start;
				}
			}
		}
		std::cout << "\n" << std::endl;
	}
	
	void dfs(bool visit[], int value) {
		if (visit[value]) {
			return;
		}
		visit[value] = true;
		std::cout << "  " << value; 
		Edge* temp = this->vertic[value].start;

		while (temp != NULL) {
			this->dfs(visit, temp->name);
			temp = temp->start;
		}
	}

	void printDFS(int value) {
		if (this->size <= 0 || value < 0 || value >= this->size) {
			return;
		}
		bool visit[this->size];

		std::cout << "DFS :" ;
		for (int i = 0; i < this->size; ++i) {
			visit[i] = false;
		}
		this->dfs(visit, value);
		std::cout << std::endl;
	}

	void bfs(int value) {
		if (value > this->size || this->size <= 0) {
			return;
		}
		std::queue<int> q;
		Edge* temp = NULL;
		bool visit[this->size];
		q.push(value);
		std::cout << "BFS :";

		while (q.empty() == false) {
			temp = this->vertic[q.front()].start;
			while (temp != NULL) {
				if (!visit[temp->name]) {
					visit[temp->name] = true;
					q.push(temp->name);
				}
				temp = temp->start;
			}
			visit[q.front()] = true;
			std::cout << "  " << q.front();
			q.pop();
		}
		std::cout << std::endl;
	}

	void minimumCycle(int start, int end, bool visit[], int sum, int length) {
		if (start >= this->size || end >= this->size || start < 0 || end < 0 || this->size <= 0) {
			return;
		}

		if (visit[start] == true) {
			if (length > 2 && start == end && sum < this->result) {
				this->result = sum;
			}
			return;
		}
		visit[start] = true;
		
		Edge* edge = this->vertic[start].start;
		while (edge != NULL) {
			this->minimumCycle(edge->name, end, visit, sum + (edge->weight), length + 1);
			edge = edge->start;
		}
		visit[start] = false;
	}

	void minWeightCycle() {
		if (this->size <= 0) {
			return;
		}
		
		bool visit[this->size];
		for (int i = 0; i < this->size; ++i) {
			visit[i] = false;
		}
		this->result = INT_MAX;

		for (int i = 0; i < this->size; ++i) {
			this->minimumCycle(i, i, visit, 0, 0);
		}
		std::cout << "Min weight cycle : " << this->result << std::endl;
	}
};

