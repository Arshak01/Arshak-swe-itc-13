#include <iostream>
#include <chrono>
#include "quick_sort.hpp"



using namespace std::chrono;


int main() {
    int size = 10;
    int arr[size] = { 5, 9, 1, 2, 7, 6, 3, 11, 4, 8};
    std::cout << "Unsorted array" << std::endl;
    print(arr,  size);
    std::cout << "Sorted array after shell sort" << std::endl;

    auto start = high_resolution_clock::now();
    shellSort(arr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(start - stop);
    print(arr, size);
    std::cout <<"Shell sort " << duration.count() << "m_secods" << std::endl;


    int array[] = {5, 45, 8, 6, 2, 1, 3, 7, 9, 25, 30};
    int n = sizeof(array)/sizeof(array[0]);
    std::cout << "Unsorted array for quick sort" << std::endl;
    print(array, n);
    std::cout << "Sorted array after quick sort" << std::endl;
    quickSort(array, 0, n - 1);
    print(array, n);

    return 0;
}
