#ifndef vector

class Vector{
private:
	int* arr;
	unsigned int capacity;
	unsigned int current;
public:
	Vector();

	Vector(int size, int defaultValue);

	void push(int val);

	void pop();

	void insert(int index, int data);

	int size();

	int getCapacity();

	int& operator [] ();

	void print();
};

#endif
