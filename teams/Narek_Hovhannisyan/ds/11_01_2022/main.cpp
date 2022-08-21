#include <iostream>
#include "checkingFunction.hpp"
#include "vectorImplementation.hpp"

int main() {
    std::string str;
    std::cout << "Please, type a string containing only ( ) [  ] {  } symbols: ";
    std::cin >> str;
    std::cout << "is " << str << " correct: ";
    std::cout << std::boolalpha << isStringCorrect(str) << std::endl;
    std::cout << std::endl;
    std::cout << "vector testing" << std::endl;
    Vector v(6);
    v.autoFill(44, 87);
    v.print();
    return 0;
}
