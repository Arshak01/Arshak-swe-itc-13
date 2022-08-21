#include <iostream>
#include "./divide/divide.hpp"
#include "./multiply/multiply.hpp"
#include "./sum/sum.hpp"
#include "./sub/sub.hpp"


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
