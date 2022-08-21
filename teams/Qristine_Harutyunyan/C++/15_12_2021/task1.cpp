#include <iostream> 

int fibonachi(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
        return fibonachi(n - 1) + fibonachi(n -2);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << "Fibonachi " << n << " is " << fibonachi(n);
    return 0;
}



