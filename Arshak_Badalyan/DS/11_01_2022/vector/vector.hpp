class Vector {
private:	
	int* array;
	int n;
	int current;

public:
	Vector();
	
	Vector(int size);
	
	Vector(int size, int value);
	
	void push(int data);
	
	void pop();
	
	void insert(int index, int data);
	
	void deleteAtIndex(int index);
	
	int operator [] (int index);
	
	void print();
	
	int size();
	
	int capacity();
	
	bool empty();
	
	~Vector();

};
