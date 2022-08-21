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

int sum (int num1 = 0, int num2 = 0) {
    return num1 + num2;
}

int main() {
    int num1 = 0;
    int num2 = 0;
    std::cout << "a = "; std::cin >> num1;
    std::cout << "b = "; std::cin >> num2;
    std::cout << "max = " << max(num1, num2) << std::endl;
    std::cout << "min = " << min(num1, num2) << std::endl;
    std::cout << "sum = " << sum(num1, num2) << std::endl;
    return 0;
}
