#include <iostream>

int askOperator(int op) {
    std::cout << "Please choose the operation that you wish to perform" << std::endl;
    std::cout << "1. Addition" << std::endl << "2. Substraction" << std::endl << "3. Multiplication" << std::endl
    << "4. Division" << std::endl << "5. Modulus" << std::endl;
    std::cin >> op;
    return op;
}

