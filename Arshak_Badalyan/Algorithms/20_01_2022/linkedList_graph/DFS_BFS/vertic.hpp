
class Vertices {
public:
    int data;
	Edge* start;
	Edge* end;
	Vertices(int data = 0,Edge* start = NULL,Edge* end = NULL) {
		this->data = data;
		this->start = start;
		this->end = end;
	}
};

