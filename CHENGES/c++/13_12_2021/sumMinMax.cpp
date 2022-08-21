#include <iostream>

void sum(int n1, int n2) {
        int sum = n1 + n2;
        std::cout << "Sum : " << sum << "\n";
}

void minMax(int n1, int n2) {
        int min;
        int max;
        if (n1 > n2) {
                max = n1;
                min = n2;
        } else {
                max = n2;
                min = n1;
        }
        std::cout << "Max : " << max << "\n";
        std::cout << "Min : " << min << "\n";
}

int main() {
        int n1;
        int n2;
        std::cout << "Entry first number " << "\n";
        std::cin >> n1;
        std::cout << "Entry second number " << "\n";
        std::cin >> n2;
        minMax(n1, n2);
        sum(n1, n2);
    return 0;
}
