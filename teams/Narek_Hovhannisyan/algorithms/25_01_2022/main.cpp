#include <iostream>
#include <vector>

int minDAC(const std::vector<int> &);
int maxDAC(const std::vector<int> &);
void print(const std::vector<int> &);

int main() {
    std::vector<int> arr{20, 13, 34, -21, 8, 1, 3, -10};
    print(arr);
    int minimum = minDAC(arr);
    std::cout << "minimum = " << minimum << std::endl;

    int maximum = maxDAC(arr);
    std::cout << "maximum = " << maximum << std::endl;

    return 0;
}

void minDAC(const std::vector<int> &arr, int &m) {
    if (!arr.size()) return;

    if (arr.size() == 1) {
        m = arr[0];
        return;
    }

    if (arr.size() != 2) {
        std::vector<int> tmp;
        int min;

        // add the last element to tmp if the arr.size is odd
        if (arr.size() % 2) tmp.push_back(arr[arr.size() - 1]);

        for (int i = 1; i < arr.size(); i += 2) {
            min = arr[i - 1] < arr[i] ? arr[i - 1] : arr[i];
            tmp.push_back(min);
        }

        minDAC(tmp, m);

    } else {
        m = (arr[0] < arr[1] ? arr[0] : arr[1]);
    }
}

int minDAC(const std::vector<int> &arr) {
    int m = 0;
    minDAC(arr, m);
    return m;
}

void maxDAC(const std::vector<int> &arr, int &m) {
    if (!arr.size()) return;

    if (arr.size() == 1) {
        m = arr[0];
        return;
    }

    if (arr.size() != 2) {
        std::vector<int> tmp;
        int max;

        // add the last element to tmp if the arr.size is odd
        if (arr.size() % 2) tmp.push_back(arr[arr.size() - 1]);

        for (int i = 1; i < arr.size(); i += 2) {
            max = arr[i - 1] > arr[i] ? arr[i - 1] : arr[i];
            tmp.push_back(max);
        }

        maxDAC(tmp, m);

    } else {
        m = (arr[0] > arr[1] ? arr[0] : arr[1]);
    }
}

int maxDAC(const std::vector<int> &arr) {
    int m = 0;
    maxDAC(arr, m);
    return m;
}

void print(const std::vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
