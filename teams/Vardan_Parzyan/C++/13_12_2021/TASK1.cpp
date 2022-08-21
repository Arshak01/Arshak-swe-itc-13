#include <iostream>

int min(int a, int b);
int max(int a, int b);
int sum(int a, int b);

int main() {
	int num1;
	int num2;
	std::cout << "Enter first integer : ";
	std::cin >> num1;
	std::cout << "Enter second integer : ";
	std::cin >> num2;
	std::cout << "Number 1 : " << num1<< std::endl;
	std::cout << "Number 2 : " << num2 << std::endl;
	std::cout << "Min : " << min(num1,num2) << std::endl;
	std::cout << "Max : " << max(num1,num2) << std::endl;
	std::cout << "Sum : " << sum(num1,num2) << std::endl;
	return 0;
}

int min(int a, int b) {
	if(a < b){
	    return a;
	} else {
	    return b;
	}
	return 0;
}

int max(int a, int b) {
	if(b > a) {
		return b;
	} else {
		return a;
	}
	return 0;
}

int sum(int a, int b) {
    return a + b;
}
