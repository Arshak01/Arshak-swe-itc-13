#include <iostream>

void swap(int *a, int *b);

void swap(float *a, float *b);

void swap(double *a, double *b);

void swap(char *a, char *b);


int main() {
    int int1 = 1;
    int int2 = 2;
    std::cout << "Before swap first num = " << int1 << ",second = " << int2 << std::endl;
    swap(&int1, &int2);
    std::cout << "After swap  first num = " << int1 << ",second = " << int2 << std::endl << std::endl;

    float float1 = 1.1;
    float float2 = 2.2;
    std::cout << "Before swap First float = " << float1 << ", second float =  " << float2 << std::endl;
    swap(&float1, &float2);
    std::cout << "After swap first = " << float1 << ",second float =  " << float2 << std::endl << std::endl;

    double double1 = 1.1;
    double double2 = 2.2;
    std::cout << "Before swap first double = " << double1 << ",second double = " << double2 << std::endl;
    swap(&double1, &double2);
    std::cout << "After swap first double = " << double1 << ",second double =  " << double2 << std::endl << std::endl;

    char char1 = 'x';
    char char2 = 'y';
    std::cout << "Before swap first char = " << char1 << ",second char =  " << char2 << std::endl;
    swap(&char1, &char2);
    std::cout << "After swap first char = " << char1 << ",second char =  " << char2 << std::endl << std::endl;


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

}
