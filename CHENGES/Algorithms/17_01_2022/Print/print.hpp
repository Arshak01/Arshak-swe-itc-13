#include <iostream>

template <typename T>
void print(T* arr, int n) {
	for(int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
