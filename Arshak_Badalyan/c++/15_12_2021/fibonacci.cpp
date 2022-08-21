#include <iostream>
 
int fib(int n) {
	if(n == 1 || n == 0) {
		return n;
	} else {
		return fib(n - 1) + fib(n - 2);
	}
}
int main () {
	int n;
	std::cout << "Please input the number of fibonacci sequence: "; 
	std::cin >> n;
    std::cout << "The " << n << " th fibonacci number is: " << fib(n) << std::endl;
    
	return 0;
}
