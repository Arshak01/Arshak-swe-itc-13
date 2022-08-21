#include <iostream>

void swap(int *num1 = 0, int *num2 = 0) {
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

void swap(float *num1 = 0, float *num2 = 0) {
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}


void swap(double *num1 = 0, double *num2 = 0) {
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

void swap(char *symb1 = 0, char *symb2 = 0) {
    *symb1 = *symb1 + *symb2;
    *symb2 = *symb1 - *symb2;
    *symb1 = *symb1 - *symb2;
}

void swap(bool *bool1 = 0, bool *bool2 = 0) {
    *bool1 = *bool1 + *bool2;
    *bool2 = *bool1 - *bool2;
    *bool1 = *bool1 - *bool2;
}


int main() {
    int iNum1 = 5;
    int iNum2 = 9;
    std::cout << "Before swap [INTEGER]" << std::endl;
    std::cout << "num1 = " << iNum1 << "; num2 = " << iNum2 << std::endl;
    swap(&iNum1, &iNum2);
    std::cout << "After swap" << std::endl;
    std::cout << "num1 = " << iNum1 << "; num2 = " << iNum2 << std::endl;

    float fNum1 = 5.5;
    float fNum2 = 9.9;
    std::cout << "\nBefore swap [FLOAT]" << std::endl;
    std::cout << "num1 = " << fNum1 << "; num2 = " << fNum2 << std::endl;
    swap(&fNum1, &fNum2);
    std::cout << "After swap" << std::endl;
    std::cout << "num1 = " << fNum1 << "; num2 = " << fNum2 << std::endl;

    double dNum1 = 3.3;
    double dNum2 = 8.8;
    std::cout << "\nBefore swap [DOUBLE]" << std::endl;
    std::cout << "num1 = " << dNum1 << "; num2 = " << dNum2 << std::endl;
    swap(&dNum1, &dNum2);
    std::cout << "After swap" << std::endl;
    std::cout << "num1 = " << dNum1 << "; num2 = " << dNum2 << std::endl;

    char symb1 = 'a';
    char symb2 = 'b';
    std::cout << "\nBefore swap [CHAR]" << std::endl;
    std::cout << "symb1 = " << symb1 << "; symb2 = " << symb2 << std::endl;
    swap(&symb1, &symb2);
    std::cout << "After swap" << std::endl;
    std::cout << "symb1 = " << symb1 << "; symb2 = " << symb2 << std::endl;

    bool bool1 = true;
    bool bool2 = false;
    std::cout << "\nBefore swap [BOOL]" << std::endl;
    std::cout << "bool1 = " << bool1 << "; bool2 = " << bool2 << std::endl;
    swap(&bool1, &bool2);
    std::cout << "After swap" << std::endl;
    std::cout << "bool1 = " << bool1 << "; bool2 = " << bool2 << std::endl;

    return 0;
}
