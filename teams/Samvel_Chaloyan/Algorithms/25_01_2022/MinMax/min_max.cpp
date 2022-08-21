#include "min_max.h"

void min_max(int array[], int left, int right, int& min, int& max) {
    
    if (left == right) {
        min = array[left];
        max = array[left];
    } else if (right - left == 1) {
        if (array[left] > array[right]) {
            min = array[right];
            max = array[left];
        } else if (array[left] < array[right]) {
            min = array[left];
            max = array[right];
        } else {
            min = array[left];
            max = array[left];
        }
    } else {
        int mid = (right + left) / 2;
        int min2, max2;
        min_max(array, left, mid, min, max);
        min_max(array, mid + 1, right, min2, max2);

        if (max < max2) {
            max = max2;
        }

        if (min > min2) {
            min = min2;
        }
    }
}

