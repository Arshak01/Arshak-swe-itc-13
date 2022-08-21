#include <iostream>
#include "MinMax/min_max.h"

int main() {
    int size = 8;
    int array[size] = {11, 4, 1, 7, 8, 5, 0, 9};
    int min;
    int max;
    std::cout << "The Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    min_max(array, 0, size - 1, min, max);

    std::cout << "Min: " << min << "\n" << "Max: " << max << std::endl;

    return 0;
}
