#include <iostream>
#include <memory>

template <typename T>
class SmartPointer {
    T *mPtr;
public:
    SmartPointer(T *ptr) {
        mPtr = ptr;
        std::cout << "Constructor" << std::endl;
    }
    ~SmartPointer() {
        delete mPtr;
        std::cout << "Destructor" << std::endl;
    }
    T& operator * () {
        return *mPtr;
    }
};

int main() {
    SmartPointer<char> ch = new char('f');
    std::cout << *ch << std::endl;

    std::shared_ptr<int> int1(new int(5));
    std::shared_ptr<int> int2(int1);
    std::cout << *int1 << std::endl;
    std::cout << *int2 << std::endl;

    return 0;

}
