#include <iostream>

class Vector {
	private:
		int m_capacity;
		int m_size;
		int* m_arr;
	public:
		Vector();
		Vector(int size, int defaultValue) {
			m_capacity = defaultValue;
			m_size = size;
			m_arr = new int[m_capacity];
		}
		
		void push(int val) {
			if (m_size == m_capacity) {
				m_capacity *= 2;
				int* temp = new int[m_capacity];
				for (int i = 0; i < m_size; ++i) {
					temp[i] = m_arr[i];
				}
				delete[] m_arr;
				m_arr = temp;
			}
			m_arr[m_size] = val;
			++m_size;
		}
		
		void pop() {
			--m_size;
		}
		
		void insert(int index, int data) {
			if (index = m_size) {
				push(data);
			}
			m_arr[index] = data;
		}

		int size() {
			return m_size;
		}

		int capacity() {
			return m_capacity;
		}
		
		int& operator [] (int n) {
			return m_arr[n];
	}

		void print() {
			for (int i = 0; i < m_size; ++i) {
				std::cout << m_arr[i] << " ";
			}
			std::cout << "\n";
		}
};			

int main() {
	Vector v(0, 1);
	std::cout << "Created a Vector object\n";
	v.push(17);
	v.push(4);
	v.push(5);
	std::cout << "Objects elements are: \n";
	v.print();
	
	int len = v.size();
	std::cout << "Size is equal to " << len << "\n";
	int maxLen = v.capacity();
	std::cout << "Capacity is equal to " << maxLen << "\n";
	v.capacity();

	v.pop();
	std::cout << "Deleted the last element.\nNew version of object is: \n";
	v.print();

	int maxLen1 = v.capacity();
	std::cout << "Capacity is equal to " << maxLen1 << "\n";
	v.capacity();

	int len1 = v.size();
	std::cout << "Size is equal to " << len1 << "\n";

	int index1 = v[1];
	std::cout << "The value at index 1 is " << index1 << "\n";
	return 0;
}
