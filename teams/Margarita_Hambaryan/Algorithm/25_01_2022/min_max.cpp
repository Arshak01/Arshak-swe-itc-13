#include <vector>
#include "min_max.hpp" 

void minAndMax(std::vector<int> &arr, int start, int end, int &min, int &max)
{
    if (start == end) {
        if (max < arr[start]) {
            max = arr[start];
        }
 
        if (min > arr[end]) {
            min = arr[end];
        }
 
        return;
    }
 
 
    if (end - start == 1) {
        if (arr[start] < arr[end]) {
            if (min > arr[start]) {   
                min = arr[start];
            }
            if (max < arr[end]) { 
                max = arr[end];
            }
        } else {
            if (min > arr[end]) {
                min = arr[end];
            }
            if (max < arr[start]) { 
                max = arr[start];
            }
        }
        return;
    }
    int mid = (start + end) / 2;
    minAndMax(arr, start, mid, min, max);
    minAndMax(arr, mid + 1, end, min, max);
}
