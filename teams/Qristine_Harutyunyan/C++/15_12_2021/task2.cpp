#include <iostream>

void isPrime(int min, int max) {
    std::cout << "Prime numbers are " ;
    bool isPrime;
    for (int i = min; i <= max; ++i) {
        isPrime = true;
        for (int j = 2; j < max/2; ++j) {
            if (i % j == 0) {
                isPrime = false;
            }
        }
        if (isPrime) {
            std::cout << i << " ";
        }
    }
}

bool isPrimeBool(int n, int i = 2) {

    if (n <= 1){
        return false;
    }
    if (n % i == 0){
        return false;
    }
    if ( i * i > n) {
        return true;
    }
    return isPrimeBool(n, i + 1);
}

void printPrime(int min, int max){
    std::cout << "Prime numbers are " ;
    for (int i = min; i <= max; ++i){
        if (isPrimeBool(i)){
            std::cout << i << ' ';
        }
    }
}

int main() {
    int min, max;
    std::cout << "Give start of diapazon";
    std::cin >> min;
    std::cout << "Give end of diapazon";
    std::cin >> max;
    isPrime(min, max);
    std::cout << "\n";
    printPrime(min, max);
}
