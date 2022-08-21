#include <iostream>
#include "brackets.hpp"

int main() {
    std::cout << "BRACKETS TESTING\n\n";
    std::string line;
    std::cout << "Pls enter a string which includes only brackets('{', '}', '(', ')', '[', ']')\n";
    std::cin >> line;
    checkingBrackets(line);
	return 0;
}
