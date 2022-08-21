#include <iostream>

void calculator(int op, int n1, int n2) {
    switch(op) {
        case 1:
            std::cout << "The result is " << n1 + n2 << std::endl;
            break;
        case 2:
            std::cout << "The result is " << n1 - n2 << std::endl;
            break;
        case 3:
            std::cout << "The result is " << n1 * n2 << std::endl;
            break;
        case 4:
            std::cout << "The result is " << n1 / n2 << std::endl;
            break;
        case 5:
            std::cout << "The result is " << n1 % n2 << std::endl;
            break;
        default:
            std::cout << "Invalid operation!" << std::endl;
    }
}
