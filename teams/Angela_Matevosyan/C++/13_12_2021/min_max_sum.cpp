#include <iostream>
int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int sum(int a, int b)
{
	return a + b;
}

int main()
{
	int a, b;
	std::cout << "Insert number 1: ";
	std::cin >> a;
	std::cout << "Insert number 2: ";
	std::cin >> b;
	std::cout << "Min: " << min(a,b) << std::endl;
	std::cout << "Max: " << max(a,b) << std::endl;
	std::cout << "Sum: " << sum(a,b) << std::endl;
	return 0;
}
