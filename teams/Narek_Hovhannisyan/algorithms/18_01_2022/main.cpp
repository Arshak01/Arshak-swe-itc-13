#include <iostream>
#include <vector>
#include <chrono>
#include "quickSort.hpp"
#include "shellSort.hpp"

using namespace std::chrono;

void print(std::vector<int>&);
void fillVector(std::vector<int>&);

int  main() {
    std::vector<int> v(1000);
    fillVector(v);
    print(v);

    auto start = high_resolution_clock::now();
    
    quickSort(v, 0, v.size() - 1);
    // shellSort(v);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    print(v);
    std::cout << "duration in microseconds = " << duration.count() << std::endl;

    return 0;
}

void print(std::vector<int> &vector) {
    std::cout << std::endl;
    for (int e : vector) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void fillVector(std::vector<int> &vector) {
    for (int i = 0; i < vector.size(); i++) {
        vector[i] = vector.size() - i;
    }
}