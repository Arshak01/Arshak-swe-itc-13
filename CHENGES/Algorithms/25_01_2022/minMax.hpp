
template <typename T>
void minMax(T* arr, int l, int r, T& min, T& max) {
	if (l == r) {
		min = max = arr[l];
	} else {
		T mid = l + (r - l) / 2;
		T leftMin;
		T leftMax;
		T rightMin;
		T rightMax;

		minMax(arr, l, mid, leftMin, leftMax);
		minMax(arr, mid + 1, r, rightMin, rightMax);

		if (leftMin < rightMin) {
			min = leftMin;
		} else {
			min = rightMin;
		}

		if (leftMax > rightMax) {
			max = leftMax;
		} else {
			max = rightMax;
		}
	}
}
