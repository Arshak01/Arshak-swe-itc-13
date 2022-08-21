#include <iostream>

int logOR(int num1 = 0, int num2 = 0) {
    return num1 | num2;
}

int logAND(int num1 = 0, int num2 = 0) {
    return num1 & num2;
}

int logXOR(int num1 = 0, int num2 = 0) {
    return num1 ^ num2;
}

int rightShift(int num1 = 0, int num2 = 0) {
    return num1 >> num2;
}

int leftShift(int num1 = 0, int num2 = 0) {
    return num1 << num2;
}

int bitwiseCalc(int num1 = 0, int num2 = 0, char sign = ' ') {
    switch (sign) {
        case '|':
            return logOR(num1, num2);
        case '&':
            return logAND(num1,num2);
        case '^':
            return logXOR(num1, num2);
        case '>':
            return rightShift(num1, num2);
        case '<':
            return leftShift(num1, num2);
        default:
            std::cout << "ERROR: Wrong input" << std::endl;
            return 0;
    }
}

int main() {
    int num1 = 0;
    int num2 = 0;
    char sign[2] = {' ', ' '};
    std::cout << "Please input one of the following: '|', '&', '^', '>>', '<<'" << std::endl;
    std::cout << "input first operand: ";
    std::cin >> num1;
    std::cout << "input second operand: ";
    std::cin >> num2;
    std::cout << "input operator: ";
    std::cin >> sign;
    if (sign[0] != sign[1] && (sign[0] == '<' || sign[0] == '>')){
        std::cout << "ERROR: Worng input" << std::endl;
    } else {
        std::cout << num1 << ' ' << sign << ' ' << num2 << " = " << bitwiseCalc(num1, num2, sign[0]) << std::endl;
    }
        return 0;
}
