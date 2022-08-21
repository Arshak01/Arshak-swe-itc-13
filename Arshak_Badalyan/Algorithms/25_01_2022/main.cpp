#include <iostream>
#include "./print.hpp"
#include "./minMax.hpp"

int main() {
	int size;
	std::cout << "Enter the size of array : ";
	std::cin >> size;
	int arr[size];
	std::cout << std::endl;

	for(int i = 0;i < size; ++i) {
		arr[i]=rand()%100; 
	}

	int r = sizeof(arr) / sizeof(arr[0]);

	int l = 0;
	int min;
	int max;
	print(arr, r);
	minMax(arr, l, r-1, min, max);	

	std::cout << "Min : " << min << std::endl;
	std::cout << "Max : " << max << std::endl;

	return 0;

}
