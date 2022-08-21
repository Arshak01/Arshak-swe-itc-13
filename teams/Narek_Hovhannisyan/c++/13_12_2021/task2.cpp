#include <iostream>

int bitwiseOr(int a, int b);

int bitwiseAnd(int a, int b);

int bitwiseXOr(int a, int b);

int bitwiseShiftLeft(int a, int b);

int bitwiseShiftRight(int a, int b);

int calculator(int a, int b, char operation);

int main() {
    std::cout << "For bitwise left shift you should type 'l', and bitwise right shift 'r'. Thanks for understanding. \n";
    int firstOperand;
    int secondOperand;
    char operation;
    std::cout << "input first operand: ";
    std::cin >> firstOperand;
    std::cout << "input second operand: ";
    std::cin >> secondOperand;
    std::cout << "input operator: ";
    std::cin >> operation;
    std::cout << firstOperand << " " << operation << " " << secondOperand << " = " << calculator(firstOperand, secondOperand, operation) << std::endl;
    return 0;
}

int calculator(int a, int b, char operation) {
    switch (operation) {
        case '|':
            return bitwiseOr(a, b);
        case '&':
            return bitwiseAnd(a, b);
        case '^':
            return bitwiseXOr(a, b);
        case 'l':
            return bitwiseShiftLeft(a, b);
        case 'r':
            return bitwiseShiftRight(a, b);
        default:
            std::cout << "There is an error in your passed third argument. Please, check and try again.";
            return 0;
    }
}

int bitwiseOr(int a, int b) {
    return a | b;
}

int bitwiseAnd(int a, int b) {
    return a & b;
}

int bitwiseXOr(int a, int b) {
    return a ^ b;
}

int bitwiseShiftLeft(int a, int b) {
    return a << b;
}

int bitwiseShiftRight(int a, int b) {
    return a >> b;
}