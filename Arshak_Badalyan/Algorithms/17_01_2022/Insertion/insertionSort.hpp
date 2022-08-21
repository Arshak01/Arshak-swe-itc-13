
template <typename T>
void insertionSort(T* arr, int n) {
	T temp;
	for(int i = 1; i < n; ++i) {
		while(arr[i] < arr[i-1] && i > 0) {
			if(arr[i] < arr[i-1]) {
				temp = arr[i];
				arr[i] = arr[i-1];
				arr[i-1] = temp;	
			}
			i--;
		}
	}
}
