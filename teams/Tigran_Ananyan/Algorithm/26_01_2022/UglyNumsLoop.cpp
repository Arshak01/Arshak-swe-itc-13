#include <iostream>
#include <chrono>

using namespace std::chrono;

int getUgly(int n) {
    int uglyArr[n];
    int i2 = 0, i3 = 0, i5 = 0;
    int step_mult2 = 2;
    int step_mult3 = 3;
    int step_mult5 = 5;
    int next_no = 1;
 
    uglyArr[0] = 1;
    for (int i = 1; i < n; i++) {
        next_no = std::min(
            step_mult2,
            std::min(step_mult3, step_mult5));
        uglyArr[i] = next_no;
        if (next_no == step_mult2) {
            i2 = i2 + 1;
            step_mult2 = uglyArr[i2] * 2;
        }
        if (next_no == step_mult3) {
            i3 = i3 + 1;
            step_mult3 = uglyArr[i3] * 3;
        }
        if (next_no == step_mult5) {
            i5 = i5 + 1;
            step_mult5 = uglyArr[i5] * 5;
        }
    }
    return next_no;
}

int main() {
    int n;
    //std::cout << "Get the n'th ugly number, n:  ";
    //std::cin >> n;
    n = 1000;
    auto start1 = high_resolution_clock::now();
    std::cout << "\nThe " << n << "'th ugly number is: " << getUgly(n) << std::endl;
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    std::cout << "\nOperation took: " << duration1.count() << " microseconds" << std::endl;
    
    n = 500;
    auto start2 = high_resolution_clock::now();
    std::cout << "\nThe " << n << "'th ugly number is: " << getUgly(n) << std::endl;
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    std::cout << "\nOperation took: " << duration2.count() << " microseconds" << std::endl;
    
    n = 1500;
    auto start3 = high_resolution_clock::now();
    std::cout << "\nThe " << n << "'th ugly number is: " << getUgly(n) << std::endl;
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    std::cout << "\nOperation took: " << duration3.count() << " microseconds" << std::endl;
    return 0;
}
