#include <iostream>
#include <vector>
#include <climits>

void minAndMaxFinder(std::vector<int> const &vec, int low, int high, int &min, int &max) {
    if(low == high) {
        if(max < vec[low]) {
            max = vec[low];
        }
        if(min > vec[high]) {
            min = vec[high];
        }
        return;
    }
    if(high - low == 1) {
        if(vec[low] < vec[high]) {
            if(min > vec[low]) {
                min = vec[low];
            }
            if(max < vec[high]) {
                max = vec[high];
            }
        }else {
            if(min > vec[high]) {
                min = vec[high];
            }
            if(max < vec[low]) {
                max = vec[low];
            }
        }
        return;
    }

    int mid = (low + high) / 2;

    minAndMaxFinder(vec, low, mid, min, max);

    minAndMaxFinder(vec, mid + 1, high, min, max);
}

int main() {
    std::vector<int> vec = {2, 6,  12, 43, 1, 32, 155, 22, 3, 36};
    int max = INT_MIN;
    int min = INT_MAX;
    int maxIndex = vec.size() - 1;

    minAndMaxFinder(vec, 0, maxIndex, min, max);
    std::cout << "The minimum element is: " << min << std::endl;
    std::cout << "The maximum element is: " << max << std::endl;
    return 0;
}
