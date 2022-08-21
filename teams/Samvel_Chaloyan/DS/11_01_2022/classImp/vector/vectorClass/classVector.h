class Vector {
	private:
		int* arr;
		int capacity;
		int current;

	public:
		Vector();
		Vector(int size);
		void push(int data);
		void pop();
		void pushAtIndex(int data, int index);
		int currentSize();
		int capacitySize();
		int operator [] (int i);
		void printVector();
		~Vector();
};
