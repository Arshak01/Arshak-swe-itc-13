#include <iostream>

int fibonacci(int num) {
        if(num == 1) {
                return 0;
        }
        if(num == 2) {
                return 1;
        }
        return fibonacci(num - 1) + fibonacci(num -2);
}       

int main() {
	int num;
        std::cout << "Please input the number of fibonacci sequence: ";
	std::cin >> num;
	std::cout << "The " << num << "th fibonacci number is: " << fibonacci(num) << std::endl;
	return 0;
}
