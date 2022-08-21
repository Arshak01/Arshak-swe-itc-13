#include <iostream>
int fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int n;
	std::cout << "Please input the number of fibonacci sequence: ";
	std::cin >> n;
	if (n >=1) {
		std::cout << "The "<< n <<"th fibonacci number is: " << fibonacci(n - 1) << std::endl;
	} else if (n == 0) {
		std::cout << "The 0th fibonacci number is 0\n";
	}
	return 0;
}
