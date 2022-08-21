#include <iostream>
#include "classStack/classStack.h"
#include "expCheck/bracketsCheck.h"

int main() {
        std::string expression;
        std::cout << "Enter sequence of brackets {, [, (, ), ], }" << std::endl;
        std::cin >> expression;
        if (bracketsCheck(expression)) {
                std::cout << "The combination of brackets is Correct" << std::endl;
        } else {
                std::cout << "The combination of brackets is Wrong" << std::endl;
        }
        return 0;
}
