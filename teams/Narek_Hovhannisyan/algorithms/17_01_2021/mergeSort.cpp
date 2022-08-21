#include <vector>
#include <iostream>

void mergeSortedParts(std::vector<int> &vector, int start, int middle, int end);

void mergeSortPreparation(std::vector<int> &vector, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSortPreparation(vector, start, middle);
        mergeSortPreparation(vector, middle + 1, end);
        mergeSortedParts(vector, start, middle, end);
    }
}

void mergeSortedParts(std::vector<int> &vector, int start, int middle, int end) {
    std::vector<int> temp;
    int i = start;
    int j = middle + 1;

    while (i <= middle && j <= end) {
        if (vector[i] < vector[j]) {
            temp.push_back(vector[i]);
            i++;
        } else {
            temp.push_back(vector[j]);
            j++;
        }        
    }

    while (i <= middle) {
        temp.push_back(vector[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(vector[j]);
        j++;
    }

    // vector = temp;
    for (int i = start; i <= end; i++) {
        vector[i] = temp[i - start];
    }
}

void mergeSort(std::vector<int> &vector) {
    mergeSortPreparation(vector, 0, vector.size() - 1);
}