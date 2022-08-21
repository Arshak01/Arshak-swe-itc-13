#include <iostream>
#include "../bajanac/bajanac.hpp"
#include "../bazmapatkac/bazm.hpp"
#include "../gumarac/gum.hpp"
#include "../hanac/hanac.hpp"


int main(){
	std::cout << "Hello to my simple calc" << std::endl;
	int a,b;
	std::cout << "enter the first number: ";
	std::cin >> a;
	std::cout << "enter the second number :";
	std::cin >> b;
	std::cout << "sum:" << gumarum(a, b) << std::endl;;
	std::cout << "sub:" << hanum( a,b) << std::endl;;
	std::cout << "division:" << bajanum(a,b) << std::endl;;
	std::cout << "multiplication:" << bazmapatkum(a, b) << std::endl;;
	
	
	return 0;
}
