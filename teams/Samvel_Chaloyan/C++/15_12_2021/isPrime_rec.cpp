#include <iostream>

bool isPrime(int n, int i = 2) {
	if (n < 2) { 
		return false;
	}
	if (n == 2) {
		return true;
	}
	if (n % i == 0) {
		return false;
	}
	if (i * i > n) {
		return false;
	} 
	return isPrime(n, i++);
}

void printPrime(int from, int to) {
	if (from > to) {
		int tmp = from;
	        from = to;
       		to = tmp;		       
	}
	if (from == to) {
		if (isPrime(from)) {
			std::cout << from << " ";
		}
		std::cout << std::endl;
		return ;	
	}
	std::cout << from ;
	if (isPrime(from)) {
		std::cout << from << " ";
	}
	std::cout << from << to;
	return printPrime(from +1, to);
}

int main() {
	printPrime(2, 2);
	printPrime(9, 4);
	return 0;
}
