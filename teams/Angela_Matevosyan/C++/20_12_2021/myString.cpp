#include <iostream>
class MyString {
	private:
		char *mString;
		int mSize = 0;
		int mCounter;
		static int mObjectsCount;
	public:
		MyString(char* string, int size) {
			mString = string;
			mSize = size;
			mCounter = ++mObjectsCount;
		}

		int length() {
			return mSize;
		}

		void print() {
			for (int i = 0; i < mSize; ++i) {
				std::cout << mString[i];
			}
			std::cout << std::endl;
		}

		void concat(char* string2, int size2) {
			char* tmp = new char[mSize + size2 + 1];
			for (int i = 0; i <= mSize; ++i)
				tmp[i] = mString[i];
			for (int i = 0; i <= size2; ++i)
				tmp[i + size2] = string2[i];
			tmp[mSize + size2 + 1] = '\0';
			mString = tmp;
			mSize = mSize + size2 + 1;;

		}

		static int getObjectsCount() {
			return mObjectsCount;
		}
};

int MyString::mObjectsCount;

int main() {
	MyString string("Hello", 5);
	string.print();
	string.concat(" World", 5);
	string.print();
	std::cout << "The length is: " << string.length() << std::endl;
	std::cout << "The count is: " << MyString::getObjectsCount();
	std::cout <<std::endl;
	return 0;
}
