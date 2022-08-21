#include <iostream>

template <typename T>
class SmartPointer {
private:
    T *ptr;

public:
    SmartPointer(T *ptr) {
        this->ptr = ptr;
    }

    T& operator *() {
        return *(this->ptr);
    }

    ~SmartPointer() {
        delete this->ptr;
    }
};

int main() {
    SmartPointer<char> ptr = new char('m');
    SmartPointer<int> ptr1 = new int(17);
	std::cout << *ptr << " " << *ptr1 << "\n";

    return 0;
}
