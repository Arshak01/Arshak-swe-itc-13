
template <typename T>
void bubbleSort(T* arr, int n){
	bool swap = true;
	T temp;
	while(swap) {
		swap = false;
		for(int i = 0; i < n-1 ; ++i) {
			if(arr[i] > arr[i+1]) {
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				swap = true;
			}
		}
	}
}
