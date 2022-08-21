#include <iostream>

void swap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}

void swap(float *a, float *b) {
    float x = *a;
    *a = *b;
    *b = x;
}

void swap(double *a, double *b) {
    double x = *a;
    *a = *b;
    *b = x;
}

void swap(char *a, char *b) {
    char x = *a;
    *a = *b;
    *b = x;
}


int main() {
    int a = 5;
    int b = 10;
    std::cout << "Before" << "\n a = " << a << "\n b = " << b << std::endl;
    swap(&a, &b);
    std::cout << "After" << "\n a = " << a << "\n b = " << b << "\n" << std::endl;

    float c = 2.3;
    float d = 4.5;
    std::cout << "Before" << "\n c = " << c << "\n d = " << d << std::endl;
    swap(&c, &d);
    std::cout << "After" << "\n c = " << c << "\n d = " << d << "\n" << std::endl;

    double e = 6.7;
    double f = 8.9;
    std::cout << "Before" << "\n e = " << e << "\n f = " << f << std::endl;
    swap(&e, &f);
    std::cout << "After" << "\n e = " << e << "\n f = " << f << "\n" << std::endl;

    char g = 'g';
    char h = 'h';
    std::cout << "Before" << "\n g = " << g << "\n h = " << h << std::endl;
    swap(&g, &h);
    std::cout << "After" << "\n g = " << g << "\n h = " << h << "\n" << std::endl;
    return 0;
}
