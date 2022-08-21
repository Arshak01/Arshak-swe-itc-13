#include <iostream>

class Vector {
private: 
	int* array;
	int n; 
	int current;
          
public:
	Vector() {
		this-> n = 1;
		this-> array = new int[n];
		this-> current = 0;
		this->n++;
	}
        
	Vector(int size) {
		this-> n = size; 
		this-> current = 0;
		this-> array = new int[size];
	}
        
	Vector(int size, int value) {
		this-> n = size;
		this-> current = n;
		this-> array = new int[current];
		for (int i = 0; i < current; ++i) {
			this->array[i] = value;
		}
	}

	void push(int data) {
		if (this->current == this->n) {
			int* temp = new int[this->n += this->n/2]; 
			for (int i = 0; i < this->n; i++) {
				temp[i] = array[i];
			}
		delete[] array;
		this->n += this->n/2;
		array = temp;
		} 
		array[current] = data;
		current++;
	}

	void pop() {
		int* newArr = new int[this->n-1];
		for (int i = 0; i < this->n; i++) {
			newArr[i] = array[i];
		}
		delete[] this->array;
		this->array = newArr;
		this->current--;
	}
       
	void insert(int index, int data) {
		int* temp = new int[this->current+1];
		if(this-> array) {
			for(int i = 0; i < index; ++i){
				temp[i] = array[i];
			}
			temp[index] = data;
			for(int i = index+1; i < current; ++i){
				temp[i] = array[i];
			}
		}
		++this-> n;
		delete[] array;
		this-> array = temp;
	}

	void deleteAtIndex(int index) {
		int* temp = new int[--this->current];
		if(this-> array) {
			for(int i = 0; i < index; ++i){
				temp[i] = array[i];
			}
			for(int i = index; i < current; ++i) {
				temp[i] = array[i+1];
			}
		}
		delete[]array;
		this-> array = temp;
	}

	int operator [] (int index) {
		if(index > this->n){
			return this->array[this->n-1];
		}
		if(index <= 0){
			return this->array[0];
		}
		return this->array[index];
	}

	void print(){
		std::cout << "Vector elements are: ";
		for (int i = 0; i < current; ++i) {
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
	}

	int size() {
		return this-> current;
	}

	int capacity() {
		return this-> n;
	}

	bool empty() {
		if(this-> array) {
			return true;
		}
		return false;
	}

	~Vector() {
		delete[] this-> array;
	}
};

int main(){
	Vector v(2,0);
	v.push(1);
	v.push(2);
	v.push(3);
	v.push(4);
	v.push(5);
	v.print();
	v.push(6);
	v.print();
	v.pop();
	v.print();
	v.deleteAtIndex(2);
	v.print();
	v.insert(2,8);
	v.print();

	std::cout << "Operator [] are : " ;
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Size : " << v.size() << std::endl;
	std::cout << "Capacity : " << v.capacity() << std::endl;
	std::cout << "Empty : " << v.empty() << std::endl;

	return 0;
}
