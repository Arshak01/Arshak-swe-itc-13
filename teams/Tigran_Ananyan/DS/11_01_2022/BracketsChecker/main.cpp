#include <iostream>
#include "BracketsChecker.hpp"
#include <string>

int main() {
    std::string BrStr;
    std::cout << "Please input string of Brackets: ";
    std::cin >> BrStr;
    std::cout << std::endl;
    if(BracketsChecker(BrStr)) {
        std::cout << "The brackets in input string are balanced" << std::endl;
    }else {
        std::cout << "The brackets in input string are not balanced" << std::endl;
    }
    return 0;
}
