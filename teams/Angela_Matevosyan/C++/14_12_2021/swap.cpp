#include <iostream>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(bool *a, bool *b) {
    bool tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 1;
    int b = 6;
    std::cout << "Before swapping int values are: ";
    std::cout << a << " " << b << std::endl;
    swap(&a, &b);
    std::cout << "After swapping int values are: ";
    std::cout << a << " " << b << std::endl;
    std::cout << std::endl;

    float c = 1.1;
    float d = 6.6;
    std::cout << "Before swapping float values are: ";
    std::cout << c << " " << d << std::endl;
    swap(&c, &d);
    std::cout << "After swapping float values are: ";
    std::cout << c << " " << d << std::endl;
    std::cout << std::endl;

    double e = 8.2;
    double f = 2.4;
    std::cout << "Before swapping double values are: ";
    std::cout << e << " " << f << std::endl;
    swap(&e, &f);
    std::cout << "After swapping double values are: ";
    std::cout << e << " " << f << std::endl;
    std::cout << std::endl;

    char ch1 = '*';
    char ch2 = '#';
    std::cout << "Before swapping char values are: ";
    std::cout << ch1 << " " << ch2 << std::endl;
    swap(&ch1, &ch2);
    std::cout << "After swapping char values are: ";
    std::cout << ch1 << " " << ch2 << std::endl;
    std::cout << std::endl;

    bool b1 = true;
    bool b2 = false;
    std::cout << "Before swapping bool values are: ";
    std::cout << b1 << " " << b2 << std::endl;
    swap(&b1, &b2);
    std::cout << "After swapping char values are: ";
    std::cout << b1 << " " << b2 << std::endl;
    return 0;
}
