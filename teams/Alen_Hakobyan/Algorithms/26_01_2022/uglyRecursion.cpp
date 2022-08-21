#include <iostream>

int divide(int num, int key);
bool isUgly(int num);
int ugly(int index);

int main() {
	int index;
	std::cout << "Input index of Ugly number : ";
	std::cin >> index;
	std::cout << "Ugly number is : " << ugly(index) << std::endl;

	return 0;
}

int divide(int num, int key) {
	while(num % key == 0) {
		num /= key;
	}
	return num;
}

bool isUgly(int num) {
	num = divide(num,2);
	num = divide(num,3);
	num = divide(num,5);
	return num == 1;
}

int ugly(int index) {
	static int num = 1;
	static int count = 1;
		++num;
		if(isUgly(num)) {
			++count;
		}
		if(count == index) {
			return num;
		}
	return ugly(index);
}
