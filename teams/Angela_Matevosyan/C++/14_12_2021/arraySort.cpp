#include <iostream>

void arrayPrinting(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void descendingOrder(int arr[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void ascendingOrder(int arr[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void reverseOrder(int arr[], int size) {
    int head = 0;
    int tail = size - 1;
    int temp;
    while (i < j) {
        temp = arr[head];
        arr[head] = arr[tail];
        arr[tail] = temp;
        head++;
        tail--;
    }
}

int main() {
    int arr[5] = {45, 21, 1, 0, 335};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Initial array is: ";
    arrayPrinting(arr, size);

    std::cout << "Reverse array is: ";
    reverseOrder(arr, size);
    arrayPrinting(arr, size);

    std::cout << "Descending array is: ";
    descendingOrder(arr, size);
    arrayPrinting(arr, size);

    std::cout << "Ascending array is: ";
    ascendingOrder(arr, size);
    arrayPrinting(arr, size);
    return 0;
}
