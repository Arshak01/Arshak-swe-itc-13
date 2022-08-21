#include <iostream>
void reverse(int array[], int len) {
    int head = 0;
    int tail = len - 1;
	int temp;
    while (head < tail) {
		temp = array[head];
        array[head] = array[tail];
        array[tail] = temp;
        ++head;
        --tail;
    }
}

void descending(int array[], int len) {
	
	int i;
	int j;
	int t;
	for (i = 0; i < len; ++i) {
		for (j = 0; j < len; ++j) {
			if (array[i] < array[j]) {
				t = array[i];
				array[i] = array[j];
				array[j] = t;
			}
		}
	}
}

void ascending(int array[], int len) {
	int i;
	int j;
	int t;	
	for (i = 0; i < len; ++i) {
		for (j = 0; j < len; ++j) {
			if (array[i] > array[j]) {
				t = array[i];
				array[i] = array[j];
				array[j] = t;
			}
		}
	}
}


void printingArray(int array[], int len) {
	std::cout << "{";
	for (int i = 0; i < len; ++i) {
		if (i == (len - 1)) {
			std::cout << array[len - 1];
		} else {
			std::cout << array[i] << ", ";
		}	
	}
	std::cout << "}" << std::endl;
}
	
	

int main() {
	int len = 5;
	int array[len] = {45, 21, 1, 0, 335};
	std::cout << "The initial array is: ";
	printingArray(array, len);
	std::cout << "\n\nThe reverse array is: ";
	reverse(array, len);
	printingArray(array, len);
	std::cout << "\n\nThe descending array is: ";
	descending(array, len);
	printingArray(array, len);
	std::cout << "\n\nThe ascending array is: ";
	ascending(array, len);
	printingArray(array, len);
	std::cout << "\n\n";
	return 0;
}
