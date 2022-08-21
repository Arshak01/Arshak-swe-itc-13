#include <iostream>
#include <chrono>

using namespace std::chrono;

void merge(int arr[], int first, int mid, int last) {
    int const leftSubArrLength = mid - first + 1;
    int const rightSubArrLength = last - mid;

    int  *leftArr = new int[leftSubArrLength];
    int  *rightArr = new int[rightSubArrLength];

    for (int i = 0; i < leftSubArrLength; i++) {
        leftArr[i] = arr[first + i];
    }
    for(int j = 0; j < rightSubArrLength; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int indexOfLeftSubArr = 0;
    int indexOfRightSubArr = 0;
    int indexOfMergedArr = first;

    while(indexOfLeftSubArr < leftSubArrLength && indexOfRightSubArr < rightSubArrLength) {
        if(leftArr[indexOfLeftSubArr] <= rightArr[indexOfRightSubArr]) {
            arr[indexOfMergedArr] = leftArr[indexOfLeftSubArr];
            indexOfLeftSubArr++;
        }
        else {
            arr[indexOfMergedArr] = rightArr[indexOfRightSubArr];
            indexOfRightSubArr++;
        }
        indexOfMergedArr++;
    }
    while (indexOfLeftSubArr < leftSubArrLength) {
        arr[indexOfMergedArr] = leftArr[indexOfLeftSubArr];
        indexOfLeftSubArr++;
        indexOfMergedArr++;
    }
    while (indexOfRightSubArr < rightSubArrLength) {
        arr[indexOfMergedArr] = rightArr[indexOfRightSubArr];
        indexOfRightSubArr++;
        indexOfMergedArr++;
    }
}



void mergeSort(int arr[], int first, int last) {
    if(first >= last) {
        return;
    }
    int mid = first + (last - first) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);
    merge(arr, first, mid, last);
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
    mergeSort(arr, 0, arrSize - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printArr(arr, arrSize);
    std::cout << "Time taken by function is " << duration.count() << " microseconds" << std::endl;
    return 0;
}
