#include <iostream>
#include "PowerSum.hpp"
#include <vector>

int main() {
    int input_num;
    int pow;
    int curr_num = 1;
    int curr_sum = 0;
    std::cout << "Please insert the number: ";
    std::cin >> input_num;
    std::cout << std::endl;
    std::cout << "Please insert the power: ";
    std::cin >> pow;
    std::cout << std::endl;
    
    std::cout << "The count of ways is: " << sumOfPowers(input_num, pow, curr_num, curr_sum) << std::endl;
    return 0;
}
