#include <vector>

void shellSort(std::vector<int> &vector) {
    int size = vector.size();
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i += gap) {
            int temp = vector[i];
            int j;
            for (j = i; j >= gap && vector[j - gap] > temp; j -= gap) {
                vector[j] = vector[j - gap];
            }
            vector[j] = temp;
        }
    }
}