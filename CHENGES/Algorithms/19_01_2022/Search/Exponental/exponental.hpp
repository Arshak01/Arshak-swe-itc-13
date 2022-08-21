
template <typename T>
T binarySearch(T* arr, int l, int r, T key) { 
		if (r >= l) { 
		int mid = l + (r - l)/2; 
  
		if (arr[mid] == key) { 
			return mid; 
		}
  
		if (arr[mid] > key) { 
			return binarySearch(arr, l, mid-1, key); 
		}
		return binarySearch(arr, mid+1, r, key); 
	} 
	return -1; 
}

template <typename T>
T exponental(T* arr, int n, T key) { 

	if (arr[0] == key) {
		return 0; 
	}
	int i = 1; 
	while (i < n && arr[i] <= key) { 
		i = i*2; 
	}
    return binarySearch(arr, i/2, std::min(i, n), key); 
} 
