#include <iostream>

namespace BitwiceCalculator {
    int AND(int num1 = 0, int num2 = 0) {
        return num1 & num2;
    }
    int OR(int num1 = 0, int num2 = 0) {
        return num1 | num2;
    }
    int XOR(int num1 = 0, int num2 = 0) {
        return num1 ^ num2;
    }
    int leftShift(int num1 = 0, int num2 = 0) {
        return num1 << num2;
    }
    int rightShift(int num1 = 0, int num2 = 0) {
        return num1 >> num2;
    }
    int calc(int num1 = 0, int num2 = 0, char sign = ' ') {
        switch (sign) {
            case '&':
            std::cout << num1 << ' ' << "&" << ' ' <<  num2 << ' ' << "=" << AND(num1, num2) << std::endl;
            return 0;
            case '|':
            std::cout << num1 << ' ' << "|" << ' ' <<  num2 << ' ' << "=" << OR(num1, num2) << std::endl;
            return 0;
            case '^':
            std::cout << num1 << ' ' << "^" << ' ' <<  num2 << ' ' << "=" << XOR(num1, num2) << std::endl;
            return 0;
            case '>':
            std::cout << num1 << ' ' << ">>" << ' ' <<  num2 << ' ' << "=" << rightShift(num1, num2) << std::endl;
            return 0;
            case '<':
            std::cout << num1 << ' ' << "<<" << ' ' <<  num2 << ' ' << "=" << leftShift(num1, num2) << std::endl;
            default:
            std::cout << "Error: wrong character" << std::endl;
            return 0;
        }
    }
}

int main() {
    int a = 0;
    int b = 0;
    char sign[2] = {' ', ' '};
    char choice = ' ';
    std::cout << "Input the first  operand: "; std::cin >> a;
    std::cout << "Input the second operand: "; std::cin >> b;
    std::cout << "Input the operator:   ([&], [|], [^], [<], [>]) "; std::cin >> sign;
    BitwiceCalculator::calc(a, b, sign[0]);
    return 0;
}
