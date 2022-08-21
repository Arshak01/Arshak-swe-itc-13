#include <iostream>
#include "ugly_number_recursion.hpp"

int divide(int x, int y) {
    while(x % y == 0) {
        x /= y;
    }   
    return x;
}

bool isUgly(int num) {
    num = divide(num,2);
    num = divide(num,3);
    num = divide(num,5);
    return num == 1;
}

int getUglyByRecursion(int index) {
    static int num = 1;
    static int count = 1;
        ++num;
        if(isUgly(num)) {
            ++count;
        }
        if(count == index) {
            return num;
        }
    return getUglyByRecursion(index);
}
