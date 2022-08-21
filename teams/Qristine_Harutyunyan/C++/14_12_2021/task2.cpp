#include <iostream>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printAscending(int arr[], int n) {
    int temp;
    for (int i = 0; i < n -1; i++){
        for ( int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n ; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printDescending(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++){
        for ( int j = i + 1; j < n; j++){
            if (arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printReverse(int arr[], int n) {
    int temp;
    for (int i = 0; i <= n/2; ++i) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {45, 21, 1, 0, 335};
    int n = 5;

    std::cout << "initial array is: " ;
    printArray(arr, n);
    std::cout << std::endl; 
 
    std::cout << "descending order is: " ;
    printDescending(arr, n);
    std::cout << std::endl; 
 
    std::cout << "ascending order is: " ;
    printAscending(arr, n);
    std::cout << std::endl; 
 
    std::cout << "revers array is: " ;
    printReverse(arr, n);
    std::cout << std::endl; 
 
    return 0;
}
