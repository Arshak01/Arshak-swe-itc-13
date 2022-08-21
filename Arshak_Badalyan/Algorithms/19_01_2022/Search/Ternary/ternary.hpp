
template <typename T>
T ternary(T* arr, int l, int r,T key) {

	if(l <= r) {
		int mid1 = l + (r - l)/3;
		int mid2 = r - (r - l)/3;

		if(key == arr[mid1]){
			return mid1;
		} else if(key == arr[mid2]) {
			return mid2;
		}

		if(key < arr[mid1]) {
			return ternary(arr, l, mid1-1, key);
		} else if(key > arr[mid2]) {
			return ternary(arr, mid2 + 1, r, key);
		} else {
			return ternary(arr, mid1+1, mid2-1, key);
		}
	}

	return -1;
}
