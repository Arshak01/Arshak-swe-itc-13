#include <iostream>

void ascending(int array[], int size) {
	for(int i = 0; i < size; i++) {
		for(int j = i + 1; j < size; j++) {
			if(array[i] > array[j]) {
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

void descending(int array[], int size) {
	for(int i = 0; i < size; i++) {
		for(int j = i + 1; j < size; j++) {
			if(array[i] < array[j]) {
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

void revers(int array[], int size) {
	for(int i = 0; i < size / 2; i++) {
		int tmp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = tmp;
	}
}

void print(int array[], int size) {
	std::cout << '{';
	for (int i = 0; i < size; i++) {
		std::cout << array[i];
        	if (i != size - 1) {
        		std::cout << ", ";
        	}
	}
	std::cout << "}\n";
}

int main() {
	int array[5] = {45, 21, 1, 0, 335};
	std::cout << "initial array is: ";
	print(array, 5);
	revers(array, 5);
	std::cout << "revers array is: ";
	print(array, 5);
	descending(array, 5);
	std::cout << "descending order is: ";
	print(array, 5);
	ascending(array, 5);
	std::cout << "ascending order is: ";
	print(array, 5);
	return 0;
}
