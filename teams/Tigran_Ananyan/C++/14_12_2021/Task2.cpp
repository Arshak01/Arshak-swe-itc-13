#include <iostream>

void print(int arr[], int length) {
    for(int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void ascending(int arr[], int length) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void descending(int arr[], int length) {
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - 1; j++) {
            if(arr[j] < arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void reversing(int arr[], int length) {
    int temp = 0;
    for(int i = 0; i < length / 2; i++) {
        temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 -i] = temp;
    }
}



int main() {
    int arr[5] = {12, 340, -32, 943, -1200};
    int length = sizeof(arr) / sizeof(*arr);
    std::cout << "Printing:  ";
    print(arr, length);
    std::cout << std::endl;
    std::cout << "To reverse:  ";
    reversing(arr, length);
    print(arr, length);
    std::cout << std::endl;
    std::cout << "To ascending:  ";
    ascending(arr, length);
    print(arr, length);
    std::cout << std::endl;
    std::cout << "To descending:  ";
    descending(arr, length);
    print(arr, length);
    std::cout << std::endl;
    return 0;
}
