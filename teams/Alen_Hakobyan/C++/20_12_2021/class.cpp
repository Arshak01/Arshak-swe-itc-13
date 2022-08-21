#include <iostream>

class String {
	
private:
	int size;
	int counter;
	static int subCounter;
	const char* string;
public:

	String(const char* value1, int count) {
		this -> string = value1;
		this -> size = ++count;
		counter = ++subCounter;
	}

	void concat(const char* value2, int count) {
		char* stringSum = new char[size + count + 1];
		for (size_t i = 0; i <= size; ++i) {
			stringSum[i] = string[i];
		}
		for (size_t i = 0; i <= count; ++i) {
			stringSum[i + count] = value2[i];
		}
		stringSum[size + count + 1] = '\0';
			string = stringSum;
			size += count;
	}

	int	length() {
		return size;
	}

	static int getObjectsCount() {
		return subCounter;
	}

	void hasSubString(const char* value3, int count) {
		for(int i = 0; i < count; ++i) {
			if(string[i] != value3[0]) {
				continue;
			}			
			if(string[i] == value3[0]) {
				if(string[i+1] == value3[1]) {
					if(string[i+2] == value3[2]) {
						std::cout << "1" << std::endl;
						break;
					}
				}
			}
		}
	}

	void print() {
		for(int i = 0; i <= size; ++i) {
			std::cout << string[i];
		}
		std::cout << std::endl;
	}
	~String() {
		delete string;
	}
};

int String::subCounter;

int main() {
	
	String str("Hello",5);
	str.print();
	str.concat(" World",5);
	str.print();
	std::cout << str.length() << std::endl;
	std::cout << String::getObjectsCount() << std::endl;
	str.hasSubString("Hel",30);

	return 0;
}
