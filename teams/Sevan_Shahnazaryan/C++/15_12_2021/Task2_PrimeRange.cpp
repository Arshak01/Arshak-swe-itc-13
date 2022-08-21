#include <iostream>

bool checkPrime(int);

int primeRec(int num1 = 0, int num2 = 0);

void primeLoop(int, int);

int main() {
    int num1 = 0;
    int num2 = 0;
    std::cout << "Input range: ";
    std::cin >> num1 >> num2;

    std::cout << "Using loop:" << std::endl;
    std::cout << "The prime numbers from the ( " << num1 << " -> " << num2 << ") range are: ";
    primeLoop(num1, num2);
    std::cout << "\b\b  \n"; //overwriting the last ", " with spaces (Removing it) from "Printing line"

    std::cout << "Using recursion:" << std::endl;
    std::cout << "The prime numbers from the ( " << num1 << " -> " << num2 << ") range are: ";
    primeRec(num1, num2);
    std::cout << "\b\b  \n";
    return 0;
}

bool checkPrime(int num) {
    for(int i = 2; i <= num / 2; ++i) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;

}

int primeRec(int num1, int num2) {
    if(num1 > num2) {
        return 0;
    } else if(checkPrime(num1) == true) {
        std::cout << num1 << ", ";
    }
    return primeRec(num1 + 1, num2);
}

void primeLoop(int num1, int num2) {
    for(num1; num1 <= num2; ++num1){
        if(checkPrime(num1) == true) {
            std::cout << num1 << ", "; //"Printing line"
        }
    }
}
