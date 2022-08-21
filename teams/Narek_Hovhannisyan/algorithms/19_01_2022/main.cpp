#include <iostream>
#include <list>
#include <utility>
#include <vector>

#include "binarySearch.hpp"

void printArray(const std::vector<int> &);
void printMatrix(const std::vector<std::vector<int>> &);
void printHashMap(const std::vector<std::list<std::pair<int, int>>> &);

int main() {
    std::vector<int> arr{1, 2, 3, 5, 8, 13, 21, 34};
    printArray(arr);

    int item = 21;

    std::cout << item << "'s index in array is ";
    std::cout << binarySearch(arr, item) << std::endl;
    std::cout << "-------------------------------" << std::endl;

    std::vector<std::vector<int>> matrix{
        {0, 7, 12, 0, 0, 0},
        {0, 0, 2, 9, 0, 0},
        {0, 0, 0, 0, 10, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 4, 0, 5},
        {0, 0, 0, 0, 0, 0}};

    printMatrix(matrix);

    std::list<std::pair<int, int>> firstVertics;
    firstVertics.emplace_back(1, 7);
    firstVertics.emplace_back(2, 12);

    std::list<std::pair<int, int>> secondVertics;
    secondVertics.emplace_back(2, 2);
    secondVertics.emplace_back(3, 9);

    std::list<std::pair<int,int>> thirdVertics;
    thirdVertics.emplace_back(4, 10);

    std::list<std::pair<int, int>> forthVertics;
    forthVertics.emplace_back(5, 1);

    std::list<std::pair<int, int>> fifthVertics;
    fifthVertics.emplace_back(3, 4);
    fifthVertics.emplace_back(5, 5);

    std::list<std::pair<int, int>> sixthVertix;

    std::vector<std::list<std::pair<int, int>>> graph2{
        firstVertics,
        secondVertics,
        thirdVertics,
        forthVertics,
        fifthVertics,
        sixthVertix};

    std::cout << "print the hashmap" << std::endl;
    printHashMap(graph2);

    return 0;
}

void printArray(const std::vector<int> &arr) {
    std::cout << std::endl;
    for (int e : arr) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void printMatrix(const std::vector<std::vector<int>> &matrix) {
    std::cout << "    ";
    for (int i = 0; i < matrix.size(); i++) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;

    for (int i = 0; i < matrix.size(); i++) {
        std::cout << i << " | ";
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " ";
            if (matrix[i][j] <= 9) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void printHashMap(const std::vector<std::list<std::pair<int, int>>> &hashmap) {
    for (int i = 0; i < hashmap.size(); i++) {
        std::cout << i << " | ";
        for (std::pair<int, int> e : hashmap[i]) {
            std::cout << "[" << e.first << "|" << e.second << "] ";
        }
        std::cout << std::endl;
    }
}