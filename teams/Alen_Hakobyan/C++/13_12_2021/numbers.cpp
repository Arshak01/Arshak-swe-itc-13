#include <iostream>

int sum(int i, int j) {
	return i + j;	
}
	
int max(int i, int j) {
	if(i > j) {
		return i;
	}
	else {
		return j;
	}
}

int min(int i, int j) {
	if(i < j) {
		return i;
	}
	else {
		return j;
	}
}

int main () {
	int i,j;
	std::cout << "Insert number 1: ";
	std::cin >> i;
	std::cout << "Insert number 2: ";
	std::cin >> j;
	std::cout << "Min: " << min(i,j) << std::endl;
	std::cout << "Max: " << max(i,j) << std::endl;
	std::cout << "Sum: " << sum(i,j) << std::endl;
	return 0;
}
