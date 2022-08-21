#include <iostream>

void swap(int *a, int *b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void swap(float *a, float *b) {
	float tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(double *a, double *b) {
	double tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(char *a, char *b) {
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(bool *a, bool *b) {
	bool tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int c = 1;
	int f = 2;
	std::cout << "Type: Int." << std::endl;
	std::cout << "First number : " << c << std::endl;
	std::cout << "Second number : " << f << std::endl;
	swap(&c, &f);
	std::cout << "First number : " << c << std::endl;
	std::cout << "Second number : " << f << std::endl;

	float p = 5.2;
	float q = 8.9;
	std::cout << "Type: Float." << std::endl;
	std::cout << "First number : " << p << std::endl;
	std::cout << "Second number : " << q << std::endl;
	swap(&p, &q);
	std::cout << "First number : " << p << std::endl;
	std::cout << "Second number : " << q << std::endl;

	double x = 7.25;
	double y = 4.12;
	std::cout << "Type: Double." << std::endl;
	std::cout << "First number : " << x << std::endl;
	std::cout << "Second number : " << y << std::endl;
	swap(&x, &y);
	std::cout << "First number : " << x << std::endl;
	std::cout << "Second number : " << y << std::endl;
	
	char a = '%';
	char s = '$';
	std::cout << "Type: Char." << std::endl;
	std::cout << "First number : " << a << std::endl;
	std::cout << "Second number : " << s << std::endl;
	swap(&a, &s);
	std::cout << "First number : " << a << std::endl;
	std::cout << "Second number : " << s << std::endl;
	
	bool m = true;
	bool n = false;
	std::cout << "Type: Bool." << std::endl;
	std::cout << "First number : " << m << std::endl;
	std::cout << "Second number : " << n << std::endl;
	swap(&m, &n);
	std::cout << "First number : " << m << std::endl;
	std::cout << "Second number : " << n << std::endl;
	return 0;
}
