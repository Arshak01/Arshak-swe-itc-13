#include <iostream>
#include "sum/sum.h"
#include "sub/sub.h"
#include "div/div.h"
#include "mod/mod.h"
#include "prod/prod.h"

int check(int a, int b, char sym) {
	switch (sym) {
		case '+': return summ(a, b);
			break;
		case '-': return subb(a, b);
			break;
		case '/': return divv(a, b);
			break;
		case '%': return modd(a, b);
			break;
		case '*': return prodd(a, b);
			break;
		default : std::cout << "Wrong operator" << std::endl;
			  return 0;
	}
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
