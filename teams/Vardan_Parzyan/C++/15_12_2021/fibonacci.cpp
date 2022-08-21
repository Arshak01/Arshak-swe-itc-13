#include <iostream>

int fibonacci(int);

int main() {
	std::cout << "Input" << std::endl;
	std::cout << "Please input the number : ";
	int fibNum;
	std::cin >> fibNum;
	std::cout << "The " << fibNum << " number of Fibonacci is : " << fibonacci(fibNum) << std::endl;
}

int fibonacci(int n) {
	if (n == 2) {	//I wanted to use a different condition,(if (n < 2) return n;) 
		return 1;	//but in this case the 5th element will not be 3, it will be 5
	}
	else if (n == 1) {
		return 0;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}
