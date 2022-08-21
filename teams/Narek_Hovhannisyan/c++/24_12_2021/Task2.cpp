#include <iostream>

template<typename T>
class SmartPointer {
private:
    T *ptr;
public:
    SmartPointer(T *ptr) {
        this->ptr = ptr;
    }

    T& operator * () {
        return *this->ptr;
    }

    ~SmartPointer() {
        delete this->ptr;
    }
};

int main() {
    SmartPointer<int> pointer = new int(10);
    std::cout << *pointer << std::endl;
    return 0;
}