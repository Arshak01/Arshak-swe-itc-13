#include <iostream>

void swap(int * num1, int * num2) {
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void swap(float * num1, float * num2) {
	float tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void swap(double * num1, double * num2) {
	double tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void swap(char * num1, char * num2) {
	char tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void swap(bool * num1, bool * num2) {
	bool tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

int main() {
	int a = 1;
	int b = 6;
	std::cout << "Swap int variables:" << std::endl;
	std::cout << a << ' ' << b << std::endl; // befor swap a is 1, b is 6
	swap(&a, &b);
	std::cout << a << ' ' << b << std::endl; // after swap a is 6, b is 1

	std::cout << "Swap float variables:" << std::endl;
	float c = 1.1;
	float d = 6.6;
	std::cout << c << ' ' << d << std::endl; // befor swap c is 1.1, d is 6.6
	swap(&c, &d);
	std::cout << c << ' ' << d << std::endl; // after swap c is 6.6, d is 1.1

	std::cout << "Swap double variables:" << std::endl;
	double e = 1.1;
	double f = 6.6;
	std::cout << e << ' ' << f << std::endl; // befor swap e is 1.1, f is 6.6
	swap(&e, &f);
	std::cout << e << ' '  << f << std::endl; // after swap e is 6.6, f is 1.1

	std::cout << "Swap char variables:" << std::endl;
	char g = '1';
	char h = '6';
	std::cout << g << ' ' << h << std::endl; // befor swap g is '1', h is '6'
	swap(&g, &h);
	std::cout << g << ' ' << h << std::endl; // after swap g is '6', h is '1'

	std::cout << "Swap bool variables:" << std::endl;
	bool i = true;
	bool j = false;
	std::cout << i << ' ' << j << std::endl; // befor swap i is true, j is false
	swap(&i, &j);
	std::cout << i << ' ' << j << std::endl; // after swap i is false, j is true

	return 0;
}
