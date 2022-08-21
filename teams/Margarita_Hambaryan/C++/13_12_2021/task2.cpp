#include <iostream>
namespace custom {
    //Left Shift operator
    int LeftShift(int num1, int num2) {
        return num1 << num2;
    }   
    
    //Right Shift operator
    int RightShift(int num1, int num2) {
        return num1 >> num2;
    }   

    //Binary XOR Operator
    int BinaryXOROperator(int num1, int num2) {
        return num1 ^ num2;
    }   
    
    //Binary OR Operator
    int BinaryOROperator(int num1, int num2) {
        return num1 | num2;
    }   

    //Binary AND Operator
    int BinaryANDOperator(int num1, int num2) {
        return num1 & num2;
    }      
}
int bitwiseCalc(int num1, int num2, char s) {
    switch (s) {
        case '<': return custom::LeftShift(num1, num2);
        case '>': return custom::RightShift(num1, num2);
        case '^': return custom::BinaryXOROperator(num1, num2);
        case '|': return custom::BinaryOROperator(num1, num2);
        case '&': return custom::BinaryANDOperator(num1, num2);
    }
    return 0;
}

int main() {
    int num1;
    int num2;
    char s;
    std::cout << "Input the first number: ";
    std::cin >> num1;
    std::cout << "Input the second number: ";
    std::cin >> num2;
    std::cout << "Choose the operator you want('&'; '|'; '^'; '<'(instead of '<<'); '>'(instead of '>>'))Input the operator: ";
    std::cin >> s;
    std::cout << "The result is: ";
    std::cout << bitwiseCalc(num1, num2, s) << std::endl;
}         
