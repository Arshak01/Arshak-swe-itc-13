
template <typename T>
T interpolation(T* arr, int l, int r, T key) {
	
	if (l <= r && key >= arr[l] && key <= arr[r]) {
	
		int pos = l + (((r - l) / (arr[r] - arr[l])) * (key - arr[l]));
		
		if (arr[pos] == key) {
			return pos;
		} else if (arr[pos] < key) {
			return interpolation(arr, pos + 1, r, key);
		} else if (arr[pos] > key) {
			return interpolation(arr, l, pos - 1, key);
		} 
	}
	return -1;
}
