
template <typename T>
void selectionSort(T* arr, int n) {
	int position = 0;
	int minIndex;
	T temp;

	while(position < n){
		minIndex = position;
		for(int i = position; i < n; ++i) {
			if(arr[i] < arr[minIndex]) {
				minIndex = i;
				temp = arr[i];
				arr[i] = arr[position];
				arr[position] = temp;
			}
		}
		position++;
		minIndex++;

	}
}
