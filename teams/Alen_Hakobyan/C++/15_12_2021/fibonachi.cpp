#include <iostream>

int fibonachi(int n) {
	if(n == 1 || n == 0) {
		return n;
	}
	else {
		return fibonachi(n - 1) + fibonachi(n - 2);
	}
}

int main() {
	int num;
	std::cout << "Please input the number of fibonacci sequence: ";
	std::cin >> num;
	std::cout << "The " << num << "th fibonacci number is: " << fibonachi(--num) << std::endl;
	
	return 0;
}
