#include <iostream>

void swap(void *a, void *b) {
    double temp = *(double *)a;
    *(double *)a = *(double *)b;
    *(double *)b = temp;
}

int main() {
    int int1 = 1;
    int int2 = 6;
    std::cout << "int1: " << int1 << ", int2: " << int2 << std::endl;
    swap(&int1, &int2);
    std::cout << "int1: " << int1 << ", int2: " << int2 << std::endl << std::endl;

    float float1 = 1.1;
    float float2 = 2.2;
    std::cout << "float1: " << float1 << ", float2:  " << float2 << std::endl;
    swap(&float1, &float2);
    std::cout << "float1: " << float1 << ", float2:  " << float2 << std::endl << std::endl;

    double double1 = 3.3;
    double double2 = 4.4;
    std::cout << "double1: " << double1 << ", double2:  " << double2 << std::endl;
    swap(&double1, &double2);
    std::cout << "double1: " << double1 << ", double2:  " << double2 << std::endl << std::endl;

    char char1 = 'a';
    char char2 = 'b';
    std::cout << "char1: " << char1 << ", char2:  " << char2 << std::endl;
    swap(&char1, &char2);
    std::cout << "char1: " << char1 << ", char2:  " << char2 << std::endl << std::endl;

    bool bool1 = true;
    bool bool2 = false;
    std::cout << "bool1: " << std::boolalpha << bool1 << ", bool2:  " << bool2 << std::endl;
    swap(&bool1, &bool2);
    std::cout << "bool1: " << std::boolalpha << bool1 << ", bool2:  " << bool2 << std::endl;

    return 0;
}
