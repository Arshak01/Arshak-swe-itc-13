#include <iostream>
#include <vector>
#include <climits>
#include "min_max.hpp"

void print(std::vector<int> arr) {
    std::cout << "All elements for this array are: ";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }   
    std::cout << "\n";
}

int main(){
    std::vector<int> arr = {17, 20, -999, 0, 500, 40, 60, 45, 4, 3, 25};
    int max = INT_MIN;
    int min = INT_MAX;
    int n = arr.size();
    minAndMax(arr, 0, n - 1, min, max);
    print(arr);
    std::cout << "The minimum element of this array is equal to: " << min << "\n";
    std::cout << "The maximum element of this array is equal to: " << max << "\n";
    return 0;
}
