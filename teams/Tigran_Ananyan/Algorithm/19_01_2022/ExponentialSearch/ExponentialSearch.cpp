int binarySearch(int arr[], int min, int max, int key) {
    if (max >= min) {
        int mid = min + (max - min)/2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            return binarySearch(arr, min, mid-1, key);
        }
        return binarySearch(arr, mid+1, max, key);
    }
    return -1;
}

int exponentialSearch(int arr[], int s, int key) {
    if (arr[0] == key) {
        return 0;
    }
    int i = 1;
    while (i < s && arr[i] <= key ) {
        i *= 2;
    }
    if(i < (s-1)) {
        return binarySearch(arr, i/2, i, key);
    }else {
        return binarySearch(arr, i / 2, s - 1, key);
    }
}
