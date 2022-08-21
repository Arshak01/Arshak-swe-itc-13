#include <iostream>
#include "functions.hpp"

int interpolationSearch(int* arr, int lowEnd, int highEnd, int key) {
	int probe  = lowEnd + ((((highEnd - lowEnd) * (key - arr[lowEnd])) / (arr[highEnd] - arr[lowEnd])));
	//std::cout << probe <<std::endl;
	if (lowEnd <= highEnd && key >= arr[lowEnd] && key <= arr[highEnd]) {
		if (arr[probe] == key) {
			return probe;
		}
		if (arr[probe] < key) {
			return interpolationSearch(arr, probe + 1, highEnd, key);
		}

		if (arr[probe] > key) {
			return interpolationSearch(arr, lowEnd, probe - 1, key);
		}
	}
	return -1;
}
