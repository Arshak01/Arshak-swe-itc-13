#include <iostream>

void prime(int a, int b) {

	if(a > b) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	} 
	for (a; a <= b; a++) {
		bool number = true;
		if (a == 0 || a == 1) {
			number = false;
		}
		for (int i = 2; i <= a/2; i++) {
			if (a % i == 0) {
				number = false;
				break;
			}
		}
		if (number == true) {
			std::cout << a << " ";
		}
	}
}

int main() {
	int a;
	int b;
	std::cout << "Please input a range: ";
	std::cin >> a >> b;
	std::cout << "The prime numbers between [" << a << ", " << b << "] : "; 
	prime(a, b);
	std::cout << std::endl;
	return 0;
}
