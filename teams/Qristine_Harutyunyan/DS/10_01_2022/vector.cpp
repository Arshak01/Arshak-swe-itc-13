#include <iostream>


class Vector {
    unsigned int size;
	int current;
	int* arr;

public:
	Vector() {
		this->size = 1;
        this->arr = new int[size];
		this->current = 0;
	}

	Vector (int size, int defaultValue = 0) {
		this->size = size;
        this->arr = new int[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = defaultValue;
		}
		this->current = size;
	}

	~Vector() {
		delete [] arr;
	}

	void print() {
       for (int i = 0; i < current; ++i) {
		   std::cout << arr[i] << " ";
	   	}
		std::cout << std::endl;
	}

	int& operator [] (int index){
        if (index > size){
			std::cout << "out of size" << std::endl;
		}

		return arr[index];
	}

	void push(int val) {
		if (current == size) {
		    int* tempArr = new int[2 * size]; // if array is filled, double it

			for (int i = 0; i < size; ++i) {
                tempArr[i] = arr[i];          // copy elements from old to new
			}

			delete [] arr;                    // delete previous array 
			size *= 2;
			arr = tempArr;
		}

        arr[current] = val;
		current++;
	}

	void pop() {
		current--;
	}

	void insertAt(int index, int value){
        if (index == size) {
			push(value);
		} else {
			if (index < current){
		    	int* tempArr = new int[size + 1];
		    	for (int i = 0; i < index; ++i) {
			    	tempArr[i] = arr[i];                 // copy before index
				}
		    	tempArr[index] = value;
				size += 1;                  	
		        for (int j = index + 1; j < size + 1; ++j) {
			    	    tempArr[j] = arr [j- 1];            //copy after index
			    	}
                }		    	
		    	delete [] arr;
			    size += 1;
			    arr = tempArr;
			}
			current++;
		}
	}

	int sizeOfArray() {
        return this->current;
	}

	int capacity() {
        return this->size;
	}

};


int main() {
    Vector v1;
	std::cout << "Add at default constructor  ";
	v1.push(100);
	std::cout << v1[0] << std::endl;
	std::cout << "Add at parametr constructor  ";
	Vector v2(2, 10);
	v2.print();
	std::cout << "Delete last element  ";
	v2.pop();
    v2.print();
	v2.push(10);
	v2.push(10);
	std::cout << "Before insert " ;
	v2.print();
	std::cout << "Insert at  ";
	v2.insertAt(1, 55);
	v2.print();
	std::cout << "size  " ;
	std::cout << v2.sizeOfArray() << std::endl;
	std::cout << "capacity  " << v2.capacity() << std::endl;

    return 0;
}
