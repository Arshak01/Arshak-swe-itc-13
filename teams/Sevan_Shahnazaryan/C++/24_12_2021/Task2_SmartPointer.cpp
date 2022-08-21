#include <iostream>

template <typename T>
class SmartPointer {
private:
    T *ptr;

public:
    SmartPointer(T *ptr) {
        this->ptr = ptr;
        std::cout << "Constructor called" << std::endl;
    }

    T& operator *() {
        return *(this->ptr);
    }

    ~SmartPointer() {
        delete this->ptr;
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    SmartPointer<int> ptr = new int(6);
    std::cout << *ptr << std::endl;
    return 0;
}
