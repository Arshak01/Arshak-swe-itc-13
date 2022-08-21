#include <iostream>

void swap(int* a, int* b) {
    int temp = *a ;
    *a = *b;
    *b = temp;
}

void swap(float *a, float* b) {
    float temp = *a ;
    *a = *b;
    *b = temp;
}

void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swap(bool* a, bool* b) {
    bool temp = *a;
    *a = *b;
    *b = temp;
}    


int main() {
    int a = 1;
    int b = 6;
    std::cout << "Int before swap` " << a << " " << b << std::endl;
    swap(&a, &b);
    std::cout << "Int after swap` " << a << " " << b << std::endl;

    float c = 1.1;
    float d = 6.6;
    std::cout << "Float before swap` " << c << " " << d << std::endl;
    swap(&c, &d);
    std::cout << "Float after swap` " << c << " " << d << std::endl;

    double e = 1.1111;
    double f = 6.6666;
    std::cout << "Double before swap` " << e << " " << f << std::endl;
    swap(&e, &f);
    std::cout << "Double after swap` " << e << " " << f << std::endl;

    char g = 'a';
    char h = 'b';
    std::cout << "Char before swap` " << g << " " << h << std::endl;
    swap(&g, &h);
    std::cout << "Char after swap` " << g << " " << h << std::endl;

    bool aa = true;
    bool bb = false;
    std::cout << "Bool before swap` " << aa << " " << bb << std::endl;
    swap(&aa, &bb);
    std::cout << "Bool after swap` " << aa << " " << bb << std::endl;

    return 0;

}
