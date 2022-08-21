
void merge(int* arr, int begin,int middle, int end){
	int left = middle - begin + 1;
	int right = end - middle;
	int arrLeft[left];
	int arrRight[right];

	for (int i = 0; i < left; ++i) {
		arrLeft[i] = arr[begin + i];
	}
	for (int j = 0; j < right; ++j){
		arrRight[j] = arr[middle + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = begin;

	while(i < left && j < right) {
		if (arrLeft[i] <= arrRight[j]){
			arr[k] = arrLeft[i];
			i++;
		} else {
			arr[k] = arrRight[j];
			j++;
		}
		k++;
	}

	while(i < left){
		arr[k] = arrLeft[i];
		i++;
		k++;
		}
	while(j < right){
		arr[k] = arrRight[j];
		j++;
		k++;
	}

}

void mergeSort(int* arr,int begin, int end){
	int middle;
	if(begin < end) {
		middle = begin + (end - begin)/2;
		mergeSort(arr, begin, middle);
		mergeSort(arr, middle + 1, end);
		merge(arr, begin, middle, end);
	}
}

