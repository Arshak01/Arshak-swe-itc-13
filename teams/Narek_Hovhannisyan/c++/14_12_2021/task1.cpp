#include <iostream>

void swap(int *a, int *b);

void swap(float *a, float *b);

void swap(double *a, double *b);

void swap(char *a, char *b);

void swap(bool *a, bool *b);

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

void swap(int *a, int *b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void swap(float *a, float *b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void swap(double *a, double *b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void swap(char *a, char *b) {
    char temp = ' ';
    temp = *a;
    *a = *b;
    *b = temp;

//    this variant works as well, but it seems a little strange to me
//    *a += *b;
//    *b = *a - *b;
//    *a -= *b;
}

void swap(bool *a, bool *b) {
    bool temp = false;
    temp = *a;
    *a = *b;
    *b = temp;
}