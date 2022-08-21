#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
	int* arr;
	unsigned int n;
	unsigned int current;
public:
	Vector();
	~Vector();
	void push(int data);
	void insert(int data, int index);
	void setIndex(int index);
	void pop();
	int size();
	int getN();
	void print();
};

#endif

