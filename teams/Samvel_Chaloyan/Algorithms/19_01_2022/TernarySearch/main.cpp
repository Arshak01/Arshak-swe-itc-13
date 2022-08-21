#include <iostream>
#include "ShellSort/shellSort.h"
#include "TernarySearch/ternarySearch.h"

int main() {
	int size = 20;
    int array[size];

    for (int i = 0; i < size; ++i) {
        array[i] = (rand() % 100);
    }
    
    shellSort(array, size);

    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    int key;
    std::cout << "Enter a KEY value for searching: ";
    std::cin >> key;

    int keyIndex = ternarySearch(array, 0, size, key);
    if (keyIndex == -1) {
        std::cout << "There is no element matching with KEY." << std::endl;
    } else {
        std::cout << "The KEY:" << array[keyIndex] << " element was found in the " << keyIndex + 1 <<
                     "th place." << std::endl;
    }
	return 0;
}
