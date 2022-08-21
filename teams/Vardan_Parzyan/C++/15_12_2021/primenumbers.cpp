#include <iostream>

void primeByLoop(int, int);
void primeByRecursion(int, int);

int main() {
    int first, last;
    std::cout << "Please enter range (2 numbers ): ";
    std::cin >> first >> last;
    std::cout << "Printing prime numbers by loop" << std::endl;
    primeByLoop(first, last);
    std::cout << "" << std::endl;
    std::cout << "Printing prime numbers by recursion ";
    primeByRecursion(first, last);
    return 0;
}

void primeByLoop(int a, int b) {
    bool isPrime;
    for (int i = a; i <= b; i++) {
        if (i == 1 || i == 0)
            continue;
        isPrime = true;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime == true) {
            std::cout << i << " , ";
        }
    }
}

void primeByRecursion(int a, int b) {
    bool isPrime;
    if (a <= b) {
        isPrime = true;
        for (int j = 2; j < a; ++j){
            if (a % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime == true) {
            std::cout << a << " , ";
        }
        primeByRecursion((a + 1), b);
    }
}
