#include <iostream>

void swap(int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void shellSort(int array[], int size) {
    int gap = size / 2;

    for (gap; gap >= 1; gap /= 2) {
        int j = gap;
        for(int i = gap; i < size; ++i) {
            j = i;
            while(j - gap >= 0 && array[j - gap] > array[j]) {
                swap(&array[j - gap], &array[j]);
                j = j - gap;
            }
        }
    }
}

int ternarySearch(int array[], int left, int right, int key) {
    int mid1 = left + (right - left) / 3;
    int mid2 = mid1 + (right - left) / 3;

    if (right - left > 0) {
        if (array[mid1] == key) {
            return mid1;
        }

        if (array[mid2] == key) {
            return mid2;
        }

        if (key < array[mid1]) {
            return ternarySearch(array, left, mid1, key);
        }

        if (key > array[mid2]) {
            return ternarySearch(array, mid2 + 1, right, key);
        } 

        return ternarySearch(array, mid1, mid2, key);
    } else {
        return -1;
    }
}

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
