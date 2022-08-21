#include <iostream>
#include "functions.hpp"

void shellSort(int* array, int n) {
	int gap = n / 2;
  	while (gap > 0){
    	for (int i = gap; i < n; i++) {
      		int temp = array[i];
      		int j = i;
      			while(j >= gap && array[j-gap] > temp){
        			array[j] = array[j - gap];
        			j -= gap;
        		}
      		array[j] = temp;
    		}
    		gap /= 2;
  	}
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    std::cout << array[i] << " ";
  std::cout << std::endl;
}

