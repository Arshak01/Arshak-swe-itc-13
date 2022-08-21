#include <iostream>
#include <cmath>

static int integer = 2;

void printPrimesInRangeUsingLoop(int start, int end);

void printPrimesInRangeUsingRecursion(int start, int end);

int main() {
    int start = 0;
    int end = 0;
    std::cout << "Please input range: ";
    std::cin >> start;
    std::cin >> end;
    printPrimesInRangeUsingLoop(start, end);
    printPrimesInRangeUsingRecursion(start, end);
    return 0;
}

void printPrimesInRangeUsingLoop(int start, int end) {
    std::cout << "Prime numbers from the (" << start << " -> " << end << ") range are: ";
    bool isPrime = true;
    for (int i = start; i <= end; ++i) {
        isPrime = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                isPrime = false;
            }
        }
        if (isPrime) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

bool isPrime(int number) {
    if (number % integer == 0) return false;
    if (integer * integer > number) return true;
    ++integer;
    return isPrime(number);
}

void printPrimesInRangeUsingRecursion(int start, int end) {
    std::cout << "Prime numbers from the (" << start;
    std::cout << " -> " << end << ") range are: ";
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}