#include <iostream>

template<class T>
class Operation {
private:
	const int row = 3;
	const int column = 3;
	T** arr = new T*[row];
public:
	Operation() {
		for(int i = 0; i < this->row; ++i) {
			arr[i] = new T[column];
		}
	}
	Operation(const Operation& oper) {
		for(int i = 0; i < this->row; ++i) {
			arr[i] = new T[column];
		}
		for(int i = 0; i < this->row; ++i) {
			for(int j = 0; j < this->column; ++j) {
				arr[i][j] = oper.arr[i][j];
			}
		}
	}
	void arrRandom() {
		for(int i = 0; i < this->row; ++i) {
			for(int j = 0; j < this->column; ++j) {
				arr[i][j] = rand() % 10;
			}
		}
	}
	static void destroy(int** arr) {
		for (int i = 0; i < 3; ++i) {
			delete arr[i];
		}
		delete arr;
	}

	void print() const {
		for (int i = 0; i < this->row; ++i) {
			for (int j = 0; j < this->column; ++j) {
				std::cout << arr[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	~Operation() {
		destroy(arr);
	}
	Operation operator + (const Operation &sum) {
		Operation tmp;
		for(int i = 0; i < this->row; ++i) {
			for(int j = 0; j < this->column; ++j) {
				tmp.arr[i][j] = this -> arr[i][j] + sum.arr[i][j];
			}
		}
		return tmp;
	}
	Operation operator - (const Operation &sub) {
		Operation tmp;
		for(int i = 0; i < this->row; ++i) {
			for(int j = 0; j < this->column; ++j) {
				tmp.arr[i][j] = this -> arr[i][j] - sub.arr[i][j];
			}
		}
		return tmp;
	}
	Operation operator * (const Operation &mult) {
		Operation tmp;
		for(int i = 0; i < this->row; ++i) {
			for(int j = 0; j < this->column; ++j) {
				tmp.arr[i][j] = this -> arr[i][j] * mult.arr[i][j];
			}
		}
		return tmp;
	}
	Operation & operator += (const Operation &sumEq) {
		Operation tmp;
		for(int i = 0; i < this->row; ++i) {
			for(int j = 0; j < this->column; ++j) {
				this -> arr[i][j] += sumEq.arr[i][j];
			}
		}
		return *this;
	}
	Operation & operator = (const Operation &equal) {
		for(int i = 0; i < this->row; ++i) {
			for(int j = 0; j < this->column; ++j) {
				this->arr[i][j] = equal.arr[i][j];
			}
		}
		return *this;
	}
};
int main() {
	srand(time(NULL));

	Operation<int> arr1 = Operation<int>();
	Operation<int> arr2 = Operation<int>();

	arr1.arrRandom();
	arr2.arrRandom();

	std::cout << "ARR-1" << std::endl;
	arr1.print();
	std::cout << "ARR-2" << std::endl;
	arr2.print();

	Operation<int> sum = arr1 + arr2;
	std::cout << "Sum of ARR-1 and ARR-2" << std::endl;
	sum.print();

	Operation<int> sub = arr1 - arr2;
	std::cout << "Sub of ARR-1 and ARR-2" << std::endl;
	sub.print();
		
	Operation<int> mult = arr1 * arr2;
	std::cout << "Mult of ARR-1 and ARR-2" << std::endl;
	mult.print();
		
	arr1 += arr2;
	std::cout << "ARR-1 += ARR-2" << std::endl;
	arr1.print();

	arr1 = arr2 ;
	std::cout << "ARR-1 = ARR-2" << std::endl;
	arr1.print();

	return 0;
}
