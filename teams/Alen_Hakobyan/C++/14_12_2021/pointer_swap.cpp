#include <iostream>

void swap(int &value1, int &value2) {
	int tmp = value1;
	value1 = value2;
	value2 = tmp;
}

void swap(float &value3, float &value4) {
	float tmp = value3;
	value3 = value4;
	value4 = tmp;
}

void swap(double &value5, double &value6) {
	double tmp = value5;
	value5 = value6;
	value6 = tmp;
}

void swap(char &value7, char &value8) {
	double tmp = value7;
	value7 = value8;
	value8 = tmp;
}

void swap(bool &value9, bool &value10) {
	double tmp = value9;
	value9 = value10;
	value10 = tmp;
}

int main() {
	int value1 = 1;
	int value2 = 6;
	std::cout << "Befor swap: value1 is " << value1 << " value2 is " << value2 << std::endl;
	swap(value1,value2);
	std::cout << "After swap: value1 is " << value1 << " value2 is " << value2 << std::endl;

	float value3 = 1.1;
	float value4 = 6.6;
	std::cout << "Befor swap: value3 is " << value3 << " value4 is " << value4 << std::endl;
	swap(value3,value4);
	std::cout << "After swap: value3 is " << value3 << " value4 is " << value4 << std::endl;

	double value5 = 1.1111;
	double value6 = 6.6666;
	std::cout << "Befor swap: value5 is " << value5 << " value6 is " << value6 << std::endl;
	swap(value5,value6);
	std::cout << "After swap: value5 is " << value5 << " value6 is " << value6 << std::endl;

	char value7 = '7';
	char value8 = '8';
	std::cout << "Befor swap: value7 is " << value7 << " value8 is " << value8 << std::endl;
	swap(value7,value8);
	std::cout << "After swap: value7 is " << value7 << " value8 is " << value8 << std::endl;

	bool value9 = true;
	bool value10 = false;
	std::cout << "Befor swap: value9 is " << value9 << " value10 is " << value10 << std::endl;
	swap(value9,value10);
	std::cout << "After swap: value9 is " << value9 << " value10 is " << value10 << std::endl;

	return 0;
}
