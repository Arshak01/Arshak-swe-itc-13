#include <iostream>
#include <vector>
#include <chrono>
#include "bubbleSort.hpp"
#include "selectSort.hpp"
#include "insertSort.hpp"
#include "mergeSort.hpp"

using namespace std::chrono;

void print(std::vector<int>);
void fillVector(std::vector<int> &vector);

int main() {
    std::vector<int> v(1000);
    fillVector(v);

    print(v);

    auto start = high_resolution_clock::now();
    // I've run each function 3 times
    // bubbleSort(v);      //duration in microseconds = 27475/25159/21501
    // selectSort(v);   //duration in microseconds = 10224/10352/10301
    // insertSort(v);   //duration in microseconds = 18750/14774/15133
    mergeSort(v);    //duration in microseconds = 2528/1473/2007
    auto stop = high_resolution_clock::now();

    print(v);
    
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "duration in microseconds = " << duration.count() << std::endl;


    return 0;
}

void print(std::vector<int> vector) {
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

