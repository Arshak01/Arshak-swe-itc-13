#include <iostream>
#include "QuickSort.hpp"

int partition(int arr[], int min, int max) {
    int pivot = arr[max];
    int i = min - 1;

    for(int j = min; j <= max - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            int swp = arr[i];
            arr[i] = arr[j];
            arr[j] = swp;
        }
    }
    int swp = arr[i + 1];
    arr[i + 1] = arr[max];
    arr[max] = swp;
    return (i + 1);
}

void quickSort(int arr[], int min, int max) {
    if(min < max) {
        int wall = partition(arr, min, max);
        quickSort(arr, min, wall - 1);
        quickSort(arr, wall + 1, max);

    }
}

void printArr(int arr[], int length) {
    for(int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
