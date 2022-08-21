#include <iostream>

void displayArray(int arr[], int size);

void ascendingSort(int arr[], int size);

void descendingSort(int arr[], int size);

void reverse(int arr[], int size);

int main() {
    int arr[] = {5, 6, 3, 7, 1, 4, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Display array: ";
    displayArray(arr, size);
    std::cout << std::endl;

    std::cout << "Display array after reversing: ";
    reverse(arr, size);
    displayArray(arr, size);
    std::cout << std::endl;

    std::cout << "Display array after ascending sort: ";
    ascendingSort(arr, size);
    displayArray(arr, size);
    std::cout << std::endl;

    std::cout << "Display array after descending sort: ";
    descendingSort(arr, size);
    displayArray(arr, size);
    std::cout << std::endl;

    return 0;
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void ascendingSort(int arr[], int size) {
    bool toggle = true;
    while (toggle) {
        toggle = false;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                arr[i] += arr[i + 1];
                arr[i + 1] = arr[i] - arr[i + 1];
                arr[i] -= arr[i + 1];
                toggle = true;
            }
        }
    }
}

void descendingSort(int arr[], int size) {
    bool toggle = true;
    while (toggle) {
        toggle = false;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                arr[i] += arr[i + 1];
                arr[i + 1] = arr[i] - arr[i + 1];
                arr[i] -= arr[i + 1];
                toggle = true;
            }
        }
    }
}

void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        arr[i] += arr[size - i - 1];
        arr[size - i - 1] = arr[i] - arr[size - i - 1];
        arr[i] -= arr[size - i - 1];
    }
}
