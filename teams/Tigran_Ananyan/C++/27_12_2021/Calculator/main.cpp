#include <iostream>
#include "./AskOper/op.hpp"
#include "./AskOper/AskNum/num.hpp"
#include "./AskOper/AskNum/CalcFunction/calc.hpp"

int main() {
    int op, n1 = 0, n2 = 0;
    std::cout << "Welcome to a simple C++ calculator app." << std::endl;
    op = askOperator(op);
    std::cout << "Enter the first value: ";
    n1 = askNumber(n1);
    std::cout << "Enter the second value: ";
    n2 = askNumber(n2);
    std::cout << std::endl;
    calculator(op, n1, n2);
    return 0;
}


