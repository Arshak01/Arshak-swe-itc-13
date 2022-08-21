#include <iostream>
#include <chrono>
#include "ugly_number_loop.hpp"
#include "ugly_number_recursion.hpp"

int main(){
    std::cout << "Finding ugly numbers using loop.\n";
    int n = 5;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << n << "th ugly number is " << getUglyByLoop(n) << "\n";
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "The first duration is " << duration.count() << " microseconds.\n\n";
    
    n = 3;
    start = std::chrono::high_resolution_clock::now();
    std::cout << n << "th ugly number is " << getUglyByLoop(n) << "\n";
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "The second duration is " << duration.count() << " microsecons.\n\n";

    n = 8;
    start = std::chrono::high_resolution_clock::now();
    std::cout << n << "th ugly number is " << getUglyByLoop(n) << "\n";
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "The third duration is " << duration.count() << " microsecons.\n\n";

	std::cout << "-----------------------------------------------\n";
	std::cout << "Finding ugly numbers with recursion.\n";    
    int m = 15;
    std::cout << m << "th ugly number is " << getUglyByRecursion(m) << "\n";
    return 0;
}
