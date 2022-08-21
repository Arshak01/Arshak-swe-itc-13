#include <iostream>

int calc(int a, int b, char bitwAction);
int operator_OR(int a, int b);
int operator_AND(int a, int b);
int operator_XOR(int a, int b);
int operator_COMPL(int a, int b);
int shiftLeft(int a, int b);
int shiftRight(int a, int b);


int main() {

    int firstNum;
    int secondNum;
    char bitwAction;
    std::cout << "Enter the first number: ";
    std::cin >> firstNum;
    std::cout << "Enter the second number: ";
    std::cin >> secondNum;
    std::cout << "Enter the bitwise operator: (use '>' | '<' for left/right shift )"<<std::endl;
    std::cin >> bitwAction;
    std::cout << firstNum<< " " << bitwAction << " " << secondNum << " = " << calc(firstNum,secondNum, bitwAction) << std::endl;
    return 0;
}

int calc(int a, int b, char bitwAction) {
    
    switch (bitwAction) {
        case '|':{
            	return operator_OR(a, b);
            	break;}
        case '&':{
            	return operator_AND(a, b);
            	break;}
        case '^':{
            	return operator_XOR(a, b);
            	break;}
        case '<':{
            	return shiftLeft(a, b);
            	break;}
        case '>':{
            	return shiftRight(a, b);
            	break;}
    }
}

int operator_OR(int a, int b) {
    	return a | b;
}

int operator_AND(int a, int b) {
    	return a & b;
}

int operator_XOR(int a, int b) {
    	return a ^ b;
}

int shiftLeft(int a, int b) {
	return a << b;
}

int shiftRight(int a, int b) {
    return a >> b;
}
