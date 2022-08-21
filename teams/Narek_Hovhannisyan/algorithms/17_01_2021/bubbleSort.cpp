#include <vector>

void bubbleSort(std::vector<int> &vector) {
    bool toggle = true;
    while(toggle) {
        toggle = false;
        for (int i = 1; i < vector.size(); i++) {
            if (vector[i - 1] > vector[i]) {
                vector[i] += vector[i - 1];
                vector[i - 1] = vector[i] - vector[i - 1];
                vector[i] -= vector[i - 1];
                toggle = true;
            }
        }
    }
}