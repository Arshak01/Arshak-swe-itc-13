#include <iostream>
int swap(int *num1, int *num2) {
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
	return *num1, *num2;
}

float swap(float *num3, float *num4) {
	float tmp;
	tmp = *num3;
	*num3 = *num4;
	*num4 = tmp;
	return *num3, *num4;
}

double swap(double *num5, double *num6) {
	double tmp;
	tmp = *num5;
	*num5 = *num6;
	*num6 = tmp;
	return *num5, *num6;
}

char swap(char *char1, char *char2) {
	char tmp;
	tmp = *char1;
	*char1 = *char2;
	*char2 = tmp;
	return *char1, *char2;
}

bool swap(bool *bool1, bool *bool2) {
	bool tmp;
	tmp = *bool1;
	*bool1 = *bool2;
	*bool2 = tmp;
	return *bool1, *bool2;
}

int main() {
	int num1;
	int num2;
	std::cout << "Input the first integer number: ";
	std::cin >> num1;
	std::cout << "Input the second integer number: ";
	std::cin >> num2;
	
	std::cout << "Before swapping\n";
	std::cout <<"First integer number is: " << num1 << std::endl;
	std::cout << "Second integer number is: " << num2 << std::endl;

	std::cout << "After swapping\n";
	swap(&num1, &num2);
	std::cout << "New first integer number is: " << num1 << std::endl;
	std::cout << "New second integer number is: " << num2 << std::endl;
	
	float num3;
	float num4;
	std::cout << "Input the first float number: ";
	std::cin >> num3;
	std::cout << "Input the second float number: ";
	std::cin >> num4;
	
	std::cout << "Before swapping\n";
	std::cout <<"First float number is: " << num3 << std::endl;
	std::cout << "Second float number is: " << num4 << std::endl;

	std::cout << "After swapping\n";
	swap(&num3, &num4);
	std::cout << "New first float number is: " << num3 << std::endl;
	std::cout << "New second float number is: " << num4 << std::endl;

	double num5;
	double num6;
	std::cout << "Input the first double number: ";
	std::cin >> num5;
	std::cout << "Input the second double number: ";
	std::cin >> num6;
	
	std::cout << "Before swapping\n";
	std::cout <<"First double number is: " << num5 << std::endl;
	std::cout << "Second double number is: " << num6 << std::endl;

	std::cout << "After swapping\n";
	swap(&num5, &num6);
	std::cout << "New first double number is: " << num5 << std::endl;
	std::cout << "New second double number is: " << num6 << std::endl;

	char char1;
	char char2;
	std::cout << "Input the first char: ";
	std::cin >> char1;
	std::cout << "Input the second char: ";
	std::cin >> char2;
	
	std::cout << "Before swapping\n";
	std::cout <<"First char is: " << char1 << std::endl;
	std::cout << "Second char is: " << char2 << std::endl;

	std::cout << "After swapping\n";
	swap(&char1, &char2);
	std::cout << "New first char is: " << char1 << std::endl;
	std::cout << "New second char is: " << char2 << std::endl;

	bool bool1;
	bool bool2;
	std::cout << "Input the first bool: ";
	std::cin >> bool1;
	std::cout << "Input the second bool: ";
	std::cin >> bool2;
	
	std::cout << "Before swapping\n";
	std::cout <<"First bool is: " << bool1 << std::endl;
	std::cout << "Second bool is: " << bool2 << std::endl;

	std::cout << "After swapping\n";
	swap(&bool1, &bool2);
	std::cout << "New first bool is: " << bool1 << std::endl;
	std::cout << "New second bool is: " << bool2 << std::endl;


	return 0;
	
}
