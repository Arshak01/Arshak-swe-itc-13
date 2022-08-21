#include <iostream>

void insertionSort(int arr[], int n) {
	for(int i = 1; i < n; ++i) {
		int current = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > current) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = current;
	}
}

void print(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }   
}

int main() {
	int arr[5] = {5, 8, 2, 7, 1}; 
	std::cout << "Before sorting.\n";
    unsigned int n = sizeof(arr) / sizeof(arr[0]);
	print(arr, n);
    insertionSort(arr, n); 
	std::cout << "\nAfter sorting.\n";
    print(arr, n);
    std::cout << "\n";
    return 0;
}           
