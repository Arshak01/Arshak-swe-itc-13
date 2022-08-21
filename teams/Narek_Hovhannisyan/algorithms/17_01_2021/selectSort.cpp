#include <vector>
#include <iostream>

void selectSort(std::vector<int> &vector) {
    std::vector<int> result;
    int min = INT32_MAX;
    int currentMin = INT32_MIN;
    for (int i = 0; i < vector.size(); i++) {
        min = INT32_MAX;
        for (int j = 0; j < vector.size(); j++) {
            if (currentMin >= vector[j]) continue;

            if (min > vector[j]) {
                min = vector[j];
            }
        }
        result.push_back(min);
        currentMin = min;
    }
    vector = result;
}
