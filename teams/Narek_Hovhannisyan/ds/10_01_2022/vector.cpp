#include <iostream>

class Vector {
private:
    int size;
    int capacity;
    int *arr;
public:
    Vector() {}

    Vector(int s) {
        this->size = s;
        this->capacity = s;
        this->arr = new int[s];
    }

    Vector(int s, int defaultValue) {
        this->size = s;
        this->capacity = s;
        this->arr = new int[s];
        for (int i = 0; i < s; i++) {
            this->arr[i] = defaultValue;
        }
    }

    ~Vector() {
        std::cout << "array memory has been freed" << std::endl;
        delete [] this->arr;
    }

    int getSize() const {
        return this->size;
    }

    int getCapacity() const {
        return this->capacity;
    }

    void push(int val) {
        if (this->capacity <= this->size) {
            this->capacity *= 2;
        }
        int *tmp = new int[capacity];
        for (int i = 0; i < this->size; i++) {
            tmp[i] = this->arr[i];
        }
        this->size += 1;
        
        tmp[this->size - 1] = val;
        delete [] this->arr;
        this->arr = tmp;
    }

    void pop() {
        this->size -= 1;
        int *tmp = new int[this->capacity];
        for(int i = 0; i < this->size; i++) {
            tmp[i] = this->arr[i];
        }
        delete this->arr;
        this->arr = tmp;
    }

    void insert(int index, int value) {
        if (this->capacity <= this->size) {
            this->capacity *= 2;
        }
        int *tmp = new int[this->capacity];
        for (int i = 0; i < index; i++) {
            tmp[i] = this->arr[i];
        }
        tmp[index] = value;
        this->size += 1;
        for (int i = index + 1; i < this->size; i++) {
            tmp[i] = this->arr[i - 1];
        }
        delete [] arr;
        this->arr = tmp;
    }

    void vDelete(int index) {
        int *tmp = new int[this->capacity];
        for(int i = 0; i < index; i++) {
            tmp[i] = this->arr[i];
        }
        for(int i = index + 1; i < this->size; i++) {
            tmp[i - 1] = this->arr[i];
        }
        this->size -= 1;
        delete this->arr;
        this->arr = tmp;
    }

    int operator [] (int index) {
        return this->arr[index];
    }

    void print() const {
        for (int i = 0; i < this->size; i++) {
            std::cout << this->arr[i] << std::endl;
        }
    }

    void autoFill(int from, int to) {
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = rand() % (to - from) + from;
        }
    }

    void autoFill() {
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = rand() % 90 + 10;
        }
    }
};

int main() {
    Vector v(5);

    v.autoFill(0, 30);
    v.print();
    std::cout << "vector size = " << v.getSize() << std::endl;
    std::cout << "capacity = " << v.getCapacity() << std::endl; 
    std::cout << std::endl;

    v.push(155);
    std::cout << "pushed 155" << std::endl;
    v.push(156);
    std::cout << "pushed 156" << std::endl;
    v.pop();
    std::cout << "pop(), delete the last element" << std::endl;
    v.insert(3, 221);
    std::cout << "inserted 221 at 3 index" << std::endl;
    v.vDelete(1);
    std::cout << "deleted second element" << std::endl;
    v.print();
    std::cout << std::endl;

    std::cout << "second element is " << v[1] << std::endl;    
    std::cout << "third element is " << v[2] << std::endl;    
    std::cout << "vector size = " << v.getSize() << std::endl;
    std::cout << "capacity = " << v.getCapacity() << std::endl; 
    std::cout << std::endl;
    
    return 0;
}
