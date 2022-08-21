#include <iostream>

class Vector {
private:
	int *vector;
	unsigned int length;
	unsigned int maxSize;
	const unsigned short defSize= 2;

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
	Vector v;
	std::cout << "Pushing, vector = {12,23,44,3}" << std::endl;
	v.push(12);
	v.push(23);
	v.push(44);
    v.push(3);
	std::cout << "Capacity = " << v.capacity() << std::endl;
	std::cout << "Size = " << v.size() << std::endl;
	v.print();
	std::cout << " Insert the value 21 to 0 index" << std::endl;
	v.insert(0,21);
	std::cout << "Capcity = " << v.capacity() << std::endl;
	std::cout << "Size = " << v.size() << std::endl;
	v.print();
	std::cout << "Popping" << std::endl;
	v.pop();
	std::cout << "Capacity = " << v.capacity() << std::endl;
	std::cout << "Size = " << v.size() << std::endl;
	v.print();
	std::cout << "v[1] = " << v[1] << std::endl;
	return 0;
}
