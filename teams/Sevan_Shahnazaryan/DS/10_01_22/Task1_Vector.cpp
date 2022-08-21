#include <iostream>
#include <cassert>

class Vector {
private:
	int *vector;
	unsigned int length;
	unsigned int maxSize;
	const unsigned short defSize= 2;

	//To avoid code duplication
	void extender() {
		if(this->length == this->maxSize) {
			this->maxSize = this->maxSize + (this->maxSize / 2);
			int *tmp = new int[this->maxSize];
			for(int i = 0; i < this->length; ++i) {
				tmp[i] = this->vector[i];
			}
			delete[] this->vector;
			this->vector = tmp;
			tmp = NULL;
		  }
	}

public:
	Vector() {
		this->vector = new int[this->defSize];
		this->maxSize = defSize;
		this-> length = 0;
	}

	Vector(int size, int defaultValue = 0) {
		this->vector = new int[size];
		if(defaultValue == 0) {
			this->length = 0;
		} else {
			this->length = size;
		}
		for(int i = 0; i < size; ++i) {
			this->vector[i] = defaultValue;
		}
		this->maxSize = defSize;
	}

	int size() const {
		return this->length;
	}

	int capacity() const {
		return this->maxSize;
	}

	void push(int val) {
		extender();
		this->vector[length] = val;
		this->length++;
	}

	void pop() {
		if(length == 0) {
			return;
		}
		this->length--;
		this->vector[length] = 0;
	}

	void insert(int index, int data) {
		extender();
		for(int i = length - 1; i >= index; --i) {
			this->vector[i+1] = this->vector[i];
		}
		this->vector[index] = data;
		this->length++;
	}

	int& operator[] (int n) {
		assert(n < this->length);
		return this->vector[n];
	}

	void print() {
		for(int i = 0; i < length; ++i) {
			std::cout << "vector[" << i << "] = " << this->vector[i] << std:: endl;
		}
	}

	~Vector() {
		delete[] this->vector;
		this->vector = NULL;
	}
};

int main() {
	Vector vec;
	std::cout << "***Pushing 1,2,4 to Vector***" << std::endl;
	vec.push(1);
	vec.push(2);
	vec.push(4);
	std::cout << "Capacity = " << vec.capacity() << std::endl;
	std::cout << "Size = " << vec.size() << std::endl;
	vec.print();
	std::cout << "***Inserting number 3 to 2nd index***" << std::endl;
	vec.insert(2,3);
	std::cout << "Capcity = " << vec.capacity() << std::endl;
	std::cout << "Size = " << vec.size() << std::endl;
	vec.print();
	std::cout << "***Popping out***" << std::endl;
	vec.pop();
	std::cout << "Capacity = " << vec.capacity() << std::endl;
	std::cout << "Size = " << vec.size() << std::endl;
	vec.print();
	std::cout << "vec[1] = " << vec[1] << std::endl;
	return 0;
}
