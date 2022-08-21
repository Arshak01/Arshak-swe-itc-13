#include <iostream>

int min(int num1 = 0, int num2 = 0) {
    if (num1 < num2) {
        return num1;
    } else {
        return num2;
    }
}

int max(int num1 = 0, int num2 = 0) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int sum(int num1 = 0, int num2 = 0) {
    return num1 + num2;
}

int main() {
    int num1 = 0;
    int num2 = 0;
    std::cout << "Insert integer number 1: ";
    std::cin >> num1;
    std::cout << "Insert integer  number 2: ";
    std::cin >> num2;
    std::cout << "***********************************************" << std::endl;
    std::cout << "Min: " << min(num1, num2) << std::endl;
    std::cout << "Min: " << max(num1, num2) << std::endl;
    std::cout << "Sum: " << sum(num1, num2) << std::endl;
    return 0;
}
