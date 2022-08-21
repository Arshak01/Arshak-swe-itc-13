#include <iostream>

int max(int a, int b) {
	if (a == b) {
		std::cout << "Two numbers are equal!" << std::endl;
		return 0;
	} else {
		if (a > b) {
			std::cout << "Max : " <<a << std::endl;
			return a;
		} else {
			std::cout << "Max : " << b << std::endl;
			return b;
		}
	}
}

int min(int a, int b) {
	if (a == b) {
		std::cout << "Two numbers are equal!" << std::endl;
		return 0;
	} else {
		if (a < b) {
			std::cout << "Min : " << a << std::endl;
			return a;
		} else {
			std::cout << "Min : " << b << std::endl;
			return b;
		}
	}
}

int sum(int a, int b) {

	std::cout << "Sum : " << a + b << std::endl;
	return a + b;
}

int main() {
	int x;
	int y;

	std::cout << "Insert number 1 : ";
	std::cin >> x;
	std::cout << "Insert number 2 : ";
	std::cin >> y ;

	min(x, y);
	max(x, y);
	sum(x, y);
	return 0;	
}
