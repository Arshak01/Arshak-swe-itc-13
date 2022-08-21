#include <iostream>

int fibonacci(int n) {
    if(n > 2) {
        return fibonacci(n - 2) + fibonacci(n - 1);
    }else{
        return 1;
    }
}

int main() {
    int nth = 0;
    std::cout << "Please input the number of fibonacci sequence ";
    std::cin >> nth;
    std::cout << "The " << nth << " fibonacci number is " << fibonacci(nth) << std::endl;
    return 0;
}
