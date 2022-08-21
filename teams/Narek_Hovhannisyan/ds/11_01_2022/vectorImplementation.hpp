class Vector {
private:
    int size;
    int capacity;
    int *arr;
public:
    Vector();

    Vector(int);

    Vector(int, int);

    ~Vector();

    int getSize() const;

    int getCapacity() const;

    void push(int);

    void pop();

    void insert(int, int);

    void vDelete(int);

    int operator [] (int);

    void print() const;

    void autoFill(int, int);

    void autoFill();

};