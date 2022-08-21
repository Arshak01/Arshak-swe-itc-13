#include <iostream>
#include <limits>

int main() {
    int number = 0;
    int unit = 0;
    int decimal = 0;
    printf("Please enter any number between 0-99: ");
    std::cin >> number;
    while (std::cin.fail() || number < 0 || number > 99) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printf("This program should take integers between 0-99: ");
        std::cin >> number;
    }
    decimal = number / 10;
    unit = number % 10;
    if (number < 0 | number > 99) {
        std::cout << "Number is out of range";
    }
    if (number >= 11 && number <= 19) {
        if (number == 11) printf("eleven ");
        if (number == 12) printf("twelve ");
        if (number == 13) printf("thirteen ");
        if (number == 14) printf("fourteen ");
        if (number == 15) printf("fifteen ");
        if (number == 16) printf("sixteen ");
        if (number == 17) printf("seventeen ");
        if (number == 18) printf("eighteen ");
        if (number == 19) printf("nineteen ");
    }
    if (decimal >= 2 && decimal <= 9) {
        if (decimal == 1) printf("ten ");
        if (decimal == 2) printf("twenty ");
        if (decimal == 3) printf("thirty ");
        if (decimal == 4) printf("forty ");
        if (decimal == 5) printf("fifty ");
        if (decimal == 6) printf("sixty ");
        if (decimal == 7) printf("seventy ");
        if (decimal == 8) printf("eighty ");
        if (decimal == 9) printf("ninety ");
    }
    if (unit >= 0 && unit <= 9) {
        if (unit == 0) printf(" zero ");
        if (unit == 1) printf(" one ");
        if (unit == 2) printf(" two ");
        if (unit == 3) printf(" three ");
        if (unit == 4) printf(" four ");
        if (unit == 5) printf(" five ");
        if (unit == 6) printf(" six ");
        if (unit == 7) printf(" seven ");
        if (unit == 8) printf(" eight ");
        if (unit == 9) printf(" nine ");
    }
    printf("\n");
    return 0;
}