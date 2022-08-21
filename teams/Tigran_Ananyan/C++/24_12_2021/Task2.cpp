#include <iostream>

template <typename T>
class SmartPointer {
public:
    SmartPointer(T *ptr) {
        this->ptr = ptr;
    }

    ~SmartPointer() {
        delete ptr;
    }

    T& operator*() {
        return *ptr;
    }

private:
    T *ptr;
};

int main() {
    SmartPointer<int> ptr = new int(12);
    std::cout << *ptr << std::endl;
    return 0;
}
