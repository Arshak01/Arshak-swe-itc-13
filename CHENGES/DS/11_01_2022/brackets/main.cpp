//#include <bits/stdc++.h>
#include <iostream>
#include "./checkBrackets.hpp"

int main() {
    std::string expration = "{(()}[]";
	std::cout << expration << std::endl;
    if (checkBrackets(expration))
        std::cout << "Balanced" << std::endl;
    else
        std::cout << "Not Balanced" << std::endl;
    return 0;
}

