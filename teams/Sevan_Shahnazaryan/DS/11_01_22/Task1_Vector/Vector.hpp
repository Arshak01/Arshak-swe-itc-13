#ifndef VECTOR
#define VECTOR
class Vector {
private:
    int *vector;
    unsigned int length;
    unsigned int maxSize;
    const unsigned short defSize= 2;

    //To avoid code duplication
    void extender();

public:
    Vector();

    Vector(int size, int defaultValue); 

    int size() const;

    int capacity() const;

    void push(int val);

    void pop();

    void insert(int index, int data);

    int& operator[] (int n);

    void print();

    ~Vector();
};

#endif
