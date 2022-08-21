#include <iostream>
#include <chrono>
using namespace std::chrono;

void merge(int*, int, int, int);
void mergeSort(int*, int, int );
void arrPrint(int*, int);

int main() {
	int array[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int size = sizeof(array) / sizeof(array[0]);
  	std::cout << "Starting MERGE sorting: \n";
	auto start = high_resolution_clock::now();
  	mergeSort(array, 0, size -1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	arrPrint(array,size);
  	std::cout << "MERGE sort complete in : " << duration.count() << " microseconds\n" <<std::endl;
  	return 0;
}

void merge(int* arr, int small, int middle, int big) {
	int num1 = middle - small + 1;
	int num2 = big - middle;
	int arr1[num1];
	int arr2[num2];
	for (int i = 0; i < num1; i++){
		arr1[i] = arr[small + i];
	}
  	for (int j = 0; j < num2; j++){
    	arr2[j] = arr[middle + 1 + j];
    	}
  	int i = 0;
  	int j = 0;
  	int s = small;
  	while (i < num1 && j < num2) {
    		if (arr1[i] <= arr2[j]) {
			arr[s] = arr2[i];
      			i++;
    		} else {
      			arr[s] = arr2[j];
      			j++;
    		}
    		s++;
  	}
  	while (i < num1) {
    		arr[s] = arr1[i];
    		i++;
    		s++;
  	}
  	while (j < num2) {
   	arr[s] = arr2[j];
    	j++;
    	s++;
  	}
}

void mergeSort(int* arr, int small, int big) {
  	if (big < small) {
    		int middle = small + (big - small) / 2;
    		mergeSort(arr, small, big);
    		mergeSort(arr, middle + 1, big);
    		merge(arr, small, middle, big);
  	}
}

void arrPrint(int* arr, int size){
	for(int i = 0; i < size; i++){
		std::cout << " | " << arr[i]; 	
	}
	std::cout <<" | "<< std::endl;
}


