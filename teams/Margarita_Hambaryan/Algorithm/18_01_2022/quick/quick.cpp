#include <iostream>
#include <vector>

void print(std::vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr.at(i) << " ";
    }
}
void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int partition(std::vector<int>& arr, int i, int j) {
	int pivot = i;
	int s1Index = i;
	int s2Index = i;
	for (int k = i + 1; k < j; ++k) {
		if (arr[k] >= arr[pivot]) {
			++s2Index;
		} else {
			++s1Index;
			swap(&arr[s1Index], &arr[k]);
			++s2Index;
		}
	}
	
	swap(&arr[pivot], &arr[s1Index]);
	pivot = s1Index;
	return pivot;
	
	
}

void quickSort(std::vector<int>& arr, int i, int j) {
	if (i == j) {
		return;
	}
	int pivot = partition(arr, i, j);
	quickSort(arr, i, pivot);
	quickSort(arr, pivot + 1, j);
	
}

void quickSort(std::vector<int>& arr) {
	quickSort(arr, 0, arr.size());
}


int main() {
    std::vector<int> arr = {5, 8, 20, 4, 17, 9, 50, 3, 7}; 

    std::cout << "Before sorting\n";
    print(arr);
    quickSort(arr);
    std::cout << "\nAfter sorting\n";
    print(arr);
    std::cout << "\n";

    return 0;
}    

