#include <iostream>
#include <chrono>

using namespace std::chrono;

void BubbleSort(int arr[], int arrSize) {
    int tmp;
    for(int i = 0; i < arrSize - 1; i++) {
        for(int j = 0; j < arrSize - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void printArr(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n" << std::endl;
}


auto start = high_resolution_clock::now();
int main() {
    int arr[10] = {1,39,8,75,6,512,43,3,45,1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, arrSize);
    BubbleSort(arr, arrSize);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printArr(arr, arrSize);
    std::cout << "Time taken by function is " << duration.count() << " microseconds" << std::endl;
    return 0;
}
