#include <iostream>

int temp;

void print(int arr[], int n) {
	std::cout << "\t";
	for(int i = 0; i < n; i++) {
		std::cout << arr[i] << " "; 
	}
	std::cout << std::endl;
}

void reverseArray(int arr[], int n) {
	std::cout << "Print revers array : " << std::endl;
	int start = 0;
    	while(start < n) {
        	temp = arr[start];
        	arr[start] = arr[n];
        	arr[n] = temp;
        	start++;
        	n--;
    	}
}  

void sortArrInc(int arr[], int n) {
	std::cout << "Print asscending array : " << std::endl;
	for(int i = 0; i < n; i++) {
   		for(int j = i + 1; j < n; j++) {
      			if(arr[j] < arr[i]) {
         			temp = arr[i];
         			arr[i] = arr[j];
         			arr[j] = temp;
      			}
   		}
	}
}

void sortArrDec(int arr[], int n) {
	std::cout << "Print desscending array : " << std::endl;
	for(int i = 0; i < n; i++) {
   		for(int j = i + 1; j < n; j++) {
      			if(arr[j] > arr[i]) {
         			temp = arr[i];
         			arr[i] = arr[j];
         			arr[j] = temp;
      			}
   		}
	}
}

int main() {
	int arr[] = {15, 40, 17, 8, 7, 2, 9, 24};
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Before sort : " << std::endl;

	print(arr, n);
	reverseArray(arr, n-1);
	print(arr, n);
	sortArrInc(arr, n);
	print(arr, n);
	sortArrDec(arr, n);
	print(arr, n);
	return 0;
}
