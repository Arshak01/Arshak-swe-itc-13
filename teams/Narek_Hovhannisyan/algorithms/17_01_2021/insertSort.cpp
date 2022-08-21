#include <vector>

void insertSort(std::vector<int> &vector) {
    for (int i = 1; i < vector.size(); i++) {
        for (int j = i; j > 0; j--) {
            if (vector[j] < vector[j - 1]) {
                vector[j] += vector[j - 1];
                vector[j - 1] = vector[j] - vector[j - 1];
                vector[j] -= vector[j - 1];
            }
        }
    }
}