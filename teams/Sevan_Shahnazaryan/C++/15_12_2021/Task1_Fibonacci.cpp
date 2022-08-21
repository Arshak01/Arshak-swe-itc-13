#include <iostream>

int fibonacci(int num = 0) {
    if(num == 1) {
        return 0;
    } else if(num == 2) {
        return 1;
    } else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int main() {
    int num = 0;
    std::cout << "Input a number for Fibonacci sequence: ";
    std::cin >> num;
    std::cout << "The " << num << "th fibonacci number is: " << fibonacci(num) << std::endl;
    return 0;
}
