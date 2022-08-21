
class Edge {
public:
	char name;
	int weight;
	Edge* start;

	Edge(char name, int weight) {
		this->name = name;
		this->weight = weight;
		this->start = NULL;
	}
};

