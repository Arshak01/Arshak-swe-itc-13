#include <iostream>
#include "./sum/sum.cpp"
#include "./sub/sub.cpp"
#include "./div/div.cpp"
#include "./mod/mod.cpp"
#include "./prod/prod.cpp"

int check(int a, int b, char sym) {
	switch (sym) {
		case '+': summ(a, b);
			break;
		case '-': subb(a, b);
			break;
		case '/': divv(a, b);
			break;
		case '%': modd(a, b);
			break;
		case '*': prodd(a, b);
			break;
		default : std::cout << "Wrong operator" << std::endl;
	}
	return 0;
}

int main() {
	int a;
	int b;
	char o;
	std::cout << "Enter first Number: ";
	std::cin >> a;
	std::cout << "Enter the operator(+|-|/|%/*): ";
	std::cin >> o;
	std::cout << "Enter second Number: ";
	std::cin >> b;
	std::cout << a << " " << o << " " << b << " = " << check(a, b, o) << std::endl;

	return 0;
}
