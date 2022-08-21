#include <iostream>
#include <vector>

void print(std::vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr.at(i) << " ";
    }   
}

void shellSort(std::vector<int>& arr) {
    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (int curIndex = gap; curIndex < arr.size(); ++curIndex) {
            int curIndexCopy = curIndex;
            int item = arr[curIndex];

            while (curIndexCopy >= gap && arr[curIndexCopy - gap] > item) {
                arr[curIndexCopy] = arr[curIndexCopy - gap];
                curIndexCopy -= gap;
            }

            arr[curIndexCopy] = item;
        }
    }
}


int main() {
    std::vector<int> arr = {5, 8, 20, 4, 17, 9, 50, 3, 7};

    std::cout << "Before sorting\n";
    print(arr);
    shellSort(arr);
    std::cout << "\nAfter sorting\n";
    print(arr);
    std::cout << "\n";

    return 0;
}
