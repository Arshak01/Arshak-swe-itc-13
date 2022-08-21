#include <iostream>
#include <math.h>

bool isPrime = true;

void primeNumbersRec(int min, int max) {
    if(min <= max) {
        isPrime = true;
        for(int i = 2; i <= min / 2; ++i) {
            if(min % i == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime && min != 1) {
            std::cout << min << ", ";
        }
        primeNumbersRec(min + 1, max);
    }
}

void primeNumbersLoop(int low, int high) {
    for(int i = low; i <= high; i++) {
        isPrime = true;
        for(int j = 2; j <= sqrt(i); j++) {
            if(i % j == 0) {
                isPrime = false;
            }
        }
        if(isPrime && i != 1) {
            std::cout << i << ", ";
        }
    }
}

int main() {
    int min = 0;
    int max = 0;
    std::cout << "Please input range's min value ";
    std::cin >> min;
    std::cout << "Please input range's max value ";
    std::cin >> max;
    std::cout << "Recursion \n The prime numbers from " << min << " to " << max << " are: ";
    primeNumbersRec(min, max);
    std::cout << "\n " << std::endl;
    std::cout << "Loop \n The prime numbers from " << min << " to " << max << " are: ";
    primeNumbersLoop(min, max);
    std::cout << "\n" << std::endl;
    return 0;
}
