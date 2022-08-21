#include <iostream>

void displayArray(int arr[], int n);

void ascendingSort(int arr[], int n);

void descendingSort(int arr[], int n);

void reverse(int arr[], int n);

void arrOfAscending(int arr[], int n) {
	int temp = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void arrOfDeascending(int arr[], int n) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void arrOfRevers(int arr[], int n) {
	int temp = 0;
	int i,j;
	for(i = 0, j = n-1; i < n/2; i++, j--) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
	}
}

void arrPrinting(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
}

int main() {
	int arr[] = {10, 50, 25, 47, 1, 34};
	int n = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Initial array is: { ";
	arrPrinting(arr,n);
	std::cout << "}"<< std::endl;

	std::cout << "Reverse array is: { ";
	arrOfRevers(arr,n);
	arrPrinting(arr,n);	
	std::cout << "}"<< std::endl;

	std::cout << "Ascending array is: { ";
	arrOfAscending(arr,n);
	arrPrinting(arr,n);
	std::cout << "}" << std::endl;

	std::cout << "Deascending array is: { ";
	arrOfDeascending(arr,n);
	arrPrinting(arr,n);
	std::cout << "}" << std::endl;

	return 0;
}
