#include <iostream>
#include "functions.hpp"


int parts(int* array, int left, int right) {
  	int pivot = array[right];
  	int i = left-1;
  	for (int j = left; j < right; j++) {
		if (array[j] <= pivot) {
		i++;     	
		int temp = array[i];
      	array[i] = array[j];
      	array[j] = temp;
    	}
  	}
	int temp = array[i+1];
	array[i+1] = array[right];
	array[right] = temp;
  	return i + 1;
}

void quickSort(int* array, int left, int right) {
  	if (left < right) {
    	int pivot = parts(array, left, right);
    	quickSort(array, left, pivot - 1);
    	quickSort(array, pivot + 1, right);
  }
}


