#include <iostream>

void reverseArr(int arr[], int n) {
    int temp = 0;
    for(int i = 0; i < n / 2; i++){
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

//I used here InsertionSort
void ascendingSort(int arr[], int n) {
    int key = 0;
    int j = 0;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }

}

void descendingSort(int arr[], int n) {
    int key = 0;
    int j = 0;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }

}

void printArr(int arr[], int n) {
    std::cout << '{';
    int i = 0;
    for(i = 0; i < (n - 1); ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[i] << '}' << std::endl;
}

int main() {
    int num = 9;
    int arr[num] = {15, 7, 98, 1325, -3, -89, 4, 9, 12};

    std::cout << "Initial array is: ";
    printArr(arr, num);

    std::cout << "Reverse array is: ";
    reverseArr(arr, num);
    printArr(arr, num);

    std::cout << "descending order is: ";
    descendingSort(arr, num);
    printArr(arr, num);

    std::cout << "ascending order is: ";
    ascendingSort(arr, num);
    printArr(arr, num);

    return 0;
}
