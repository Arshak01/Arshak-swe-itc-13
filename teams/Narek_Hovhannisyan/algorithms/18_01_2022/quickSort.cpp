#include <vector>
#include <iostream>

int Partition(std::vector<int> &, int, int);

void quickSort(std::vector<int> &vector, int start, int end) {
    if (start < end) {
        int p = Partition(vector, start, end);
        quickSort(vector, start, p - 1);
        quickSort(vector, p + 1, end);
    }
}

int Partition(std::vector<int> &vector, int start, int end) {
    int finalPivotIndex = start;
    int pivot = end;

    for (int i = start; i < end; i++) {
        if (vector[i] < vector[pivot]) {
            std::swap(vector[i], vector[finalPivotIndex]);
            finalPivotIndex++;
        }
    }
    std::swap(vector[finalPivotIndex], vector[pivot]);
    return finalPivotIndex;
}
