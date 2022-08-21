#include <iostream>

int min(int a, int b);

int max(int a, int b);

int sum(int a, int b);

int main() {
    int number1;
    int number2;

    std::cout << "Insert number 1: ";
    std::cin >> number1;
    std::cout << "Insert number 2: ";
    std::cin >> number2;

    std::cout << "number1: " << number1 << ", number2: " << number2 << std::endl;
    std::cout << "Min: " << min(number1, number2) << std::endl;
    std::cout << "Max: " << max(number1, number2) << std::endl;
    std::cout << "Sum: " << sum(number1, number2) << std::endl;

    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int sum(int a, int b) {
    return a + b;
}