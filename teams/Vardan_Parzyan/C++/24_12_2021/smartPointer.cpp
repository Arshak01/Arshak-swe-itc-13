#include <iostream>
#include <memory>

template<typename T>

class SmartPointer {
private:
    T *ptr;

public:
    SmartPointer(T *ptr) {
        this-> ptr = ptr;
    }
    
    T& operator* (){
        return *ptr;
    }

    ~SmartPointer(){
        delete ptr;
        }
};


int main(){
    SmartPointer<int> smartPointer = new int (13);
    std::cout << *smartPointer << std::endl; 
    std::unique_ptr<int> uniq_ptr(new int(15));
    std::unique_ptr<int> uniq_ptr2;
    uniq_ptr2 = move(uniq_ptr);
    std::cout << *uniq_ptr2 << std::endl;
    std::shared_ptr<int> shared_ptr(new int(20));
    std::shared_ptr<int> shared_ptr2(shared_ptr);
    std::cout << *shared_ptr << std::endl;
    std::cout << *shared_ptr2 << std::endl;

    return 0;
}