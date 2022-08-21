#include <iostream>
#include <cstring>

class String {
	private:
		const char *string;
		int size;
		static int counter;
	public:
		String(const char* string1, int size) {
			this -> string = string1;
			this -> size = size;
			this -> counter ++;
		}

		~String() {
			--counter;
		}

		int length () {
			return this -> size;
		}

		void print() {
			for (int i = 0; i <= this -> size; ++i) {
				std::cout << this -> string[i];
			}
			std::cout << std::endl;
		}

		void concat(const char* string2, int size2) {
			char* tmp = new char[this -> size + size2 + 1];
			for (int i = 0; i <= this -> size; ++i) {
				tmp[i] = string[i];
			}

			for (int i = 0; i <= size2; ++i) {
				tmp[this -> size + i] = string2[i];
			}

			tmp[this -> size + size2] = '\0';
			this -> string = tmp;
			this -> size += size2;
		}

		static int getObjectsCount () {
			return counter;
		}
};

int String::counter = 0;

int main() {
	String firstString("Hello", 5);
	firstString.print();
	std::cout << firstString.length() << std::endl;
	firstString.concat(" World", 6);
	firstString.print();
	std::cout << firstString.length() << std::endl;	
	std::cout << String::getObjectsCount() << std::endl;
	return 0;
}
