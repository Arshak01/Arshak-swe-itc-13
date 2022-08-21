#include <iostream>
#include "b/sum.hpp"
#include "c/sub.hpp"
#include "c/d/divv.hpp"
#include "c/d/e/mult.hpp"

int calculator(int num1, int num2, char operation);

int main() {
    int num1;
    int num2;
    char operation;
    std::cout << "Hi. I am calculator and can count sum/subtract/product/division of two float numbers.\n";
    std::cout << "Pls, enter the first number: ";
    std::cin >> num1;

    std::cout << "Pls, enter the operation you want(+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Pls, enter the second number: ";
    std::cin >> num2;
	
	int result;
	result = calculator(num1, num2, operation);
    std::cout << "\n\n" << num1 << " " << operation << " " << num2 << " = " << result << "\n";

    return 0;
}




int calculator(int num1, int num2, char operation) {
    switch(operation) {
        case '/': {
            return divv(num1, num2);
        }
        case '*': {
            return mult(num1, num2);
        }
        case '-': {
            return sub(num1, num2);
        }
        case '+': {
            return sum(num1, num2);
        }
    }
    return 0;
}
