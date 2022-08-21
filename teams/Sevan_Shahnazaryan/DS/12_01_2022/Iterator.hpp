#ifndef ITER
#define ITER
#include "Node.hpp"
#include "List.hpp"

class Iterator {
private:
	Node *it;

public:
	Iterator();

	Iterator(Node *it);

	Node* getIt() const;

	void setIt(Node *it);

	Iterator begin();

	Iterator end();

	Iterator& operator++();

	Iterator operator++(int);

	Iterator& operator--();
	
	Iterator operator--(int);

	bool operator!=(const Iterator &obj);

	void printIt();
};

#endif
