#include <iostream>

int countWays(int n) {
    if (n == 1) {
        return 4;
    }
    int countB = 1;
    int countS = 1;
    int prev_countB;
    int prev_countS;

    for (int i = 2; i <= n; i++) {
        prev_countB = countB;
        prev_countS = countS;
 
        countS = prev_countB + prev_countS;
        countB = prev_countS;
    }

    int result = countS + countB;
    return (result*result);
}

int main() {
    int n = 4;
    std::cout << "Count of ways for " << n
         << " sections is " << countWays(n) << std::endl;
    return 0;
}
