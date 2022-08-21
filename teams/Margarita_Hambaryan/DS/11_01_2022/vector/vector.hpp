class Vector {
    private:
        int m_capacity;
        int m_size;
        int* m_arr;
    public:
        Vector();
		
		Vector(int);

        Vector(int, int);

        void push(int);

        void pop();

        void insert(int, int); 

        int size();

        int capacity();

        int operator [] (int);
	
	    void print();
};
