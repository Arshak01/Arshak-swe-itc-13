#include <iostream>

int fibo(int n) {
	if (n <= 1) {
		return n;
	}
	return fibo(n-1) + fibo(n-2);
}

int main() {
	int n;
	std::cout << "Please input the number of fibonacci sequence: ";
	std::cin >> n;
	std::cout << "The "<< n << " th fibonacci number is: " << fibo(n) << std::endl; 
	return 0;
}
