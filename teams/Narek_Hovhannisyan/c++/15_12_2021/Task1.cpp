#include <iostream>

int fibonacci(int n);

int main() {
    int nth = 0;
    std::cout << "Please input the number of fibonacci sequence: ";
    std::cin >> nth;
    //the index of fibonacci number is equal typed number - 1;
    int fibonacciNthNumberIndex = nth - 1;
    std::cout << "The " << nth << "th fibonacci number is: " << fibonacci(fibonacciNthNumberIndex) << std::endl;
    return 0;
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}