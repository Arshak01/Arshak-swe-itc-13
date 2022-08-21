#include <iostream>

class Vector {
	private:
		int* arr;
		int capacity;
		int current;

	public:
		Vector() {
			this ->	arr = new int[30];
			this -> capacity = 30;
			this -> current = 0;
		}

		Vector(int size) {
			this -> arr = new int[size];
			this -> capacity = size;
		}
		
		void push(int data);
		void pop();
		void pushAtIndex(int data, int index);
		int currentSize();
		int capacitySize();
		int operator [] (int i) {
			if (i < this -> current) {
				return this -> arr[i];
			} else {
				std::cout << "Does Not Exist!" << std::endl;
			       	exit(1);	
			}
		}

		void printVector();

		~Vector() {
			delete[] this -> arr;
		}	
};

void Vector::push(int data) {
	if (this -> current == this -> capacity) {
		int* tmp = new int[2 * this -> capacity];
		for (int i = 0; i < this -> capacity; ++i) {
			tmp[i] = this -> arr[i];
		}

		delete[] this -> arr;
		this -> capacity *= 2;
		this -> arr = tmp;
	}

	this -> arr[this -> current] = data;
	this -> current++;
}

void Vector::pop() {
	this -> current--;
}

void Vector::pushAtIndex(int data, int index) {
	if (index == this -> capacity) {
		push(data);
	} else {
		this -> arr[index] = data;
	}
}

int Vector::currentSize() {
	return this -> current;
}

int Vector::capacitySize() {
	return this -> capacity;
}

void Vector::printVector() {
	for (int i = 0; i < this -> current; ++i) {
		std::cout << this -> arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	Vector num;
	num.push(1);
	num.push(2);
	num.push(3);
	num.push(4);
	std::cout << "The elements of the Vector: ";
	num.printVector();
	std::cout << "The number of elements: ";
	std::cout << num.currentSize() << std::endl;
	num.pop();
	std::cout << "The number of elements after deleted last one: ";
	std::cout << num.currentSize() << std::endl;

	std::cout << "Enter a number to print the element: ";
	int n;
	std::cin >> n;
	std::cout << "The " << n << "th element: ";
	std::cout << num[n - 1] << std::endl;
	return 0;
}
