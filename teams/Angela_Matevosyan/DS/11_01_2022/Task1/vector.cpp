#include <iostream>
#include "vector.hpp"

Vector::Vector() {
	std::cout << "Default constructor called.\n";
	arr = new int[1];
	capacity = 1;
	current = 0;
}

Vector::Vector(int size, int defaultValue) {
	std::cout << "Constructor with parametres called.\n";
	arr = new int[size];
	for (int i = 0; i < size; ++i)
		arr[i] = defaultValue;

	capacity = size;
	current = size;
}

void Vector::push(int val) {
	if (current == capacity) {
		int* temp = new int[2 * capacity];

		for (int i = 0; i < capacity; ++i)
			temp[i] = arr[i];

		delete[] arr;
		capacity *= 2;
		arr = temp;
	}
	arr[current] = val;
	++current;
}

void Vector::pop() {
	--current;
}

void Vector::insert(int index, int data) {
	if (index == capacity)
		push(data);
	else {
		if (index < current) {
			int* temp = new int[capacity + 1];
			for (int i = 0; i < index; ++i)
				temp[i] = arr[i];
			temp[index] = data;
			++capacity;
			for (int j = index + 1; j < capacity + 1; ++j)
				temp[j] = arr[j - 1];
			delete [] arr;
			arr = temp;
		}
		++current;
	}
}
