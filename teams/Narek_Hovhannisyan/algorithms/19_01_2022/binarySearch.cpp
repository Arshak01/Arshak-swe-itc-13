#include <vector>

int binarySearch(const std::vector<int> &arr, int start, int end, int item) {
    if (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == item) {
            return mid;
        }

        if (item > arr[mid]) {
            binarySearch(arr, mid + 1, end, item);
        } else {
            binarySearch(arr, start, mid - 1, item);
        }
    } else {
        // very strange case, without else block doesn't work properly
        return -1;
    }
}

int binarySearch(const std::vector<int> &arr, int item) {
    return binarySearch(arr, 0, arr.size() - 1, item );
}