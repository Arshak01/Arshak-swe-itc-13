#ifndef VECTOR
#define VECTOR

class Vector {
private:
	int *vector;
	unsigned int length;
	unsigned int maxSize;
	const unsigned short defSize = 2;

	void extender();

public:
	Vector();

	Vector(int, int);

    int size() const;

    int capacity() const;

	void push(int);

	void pop();

	void insert(int, int);

    int& operator[] (int);

	void print();

	~Vector();
};

#endif
