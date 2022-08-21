#include <cmath>

template <typename T>
void shellSort(T* arr, int n) {
	T temp;
	int gap = sqrt(n);
	int j;

	for(int i = n; gap > 0; gap/=2) {
		for(int i = gap; i < n; ++i) {
			int j = i;	
			temp = arr[i];	
			while(temp < arr[j-gap] && j >= gap) {
				arr[j] = arr[j-gap];
				j = j-gap;
			}
			arr[j] = temp;
		}	
	}
}
