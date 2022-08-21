#include <iostream>

class Figure {
	public:
		virtual void print() = 0;
};

class Rectangle: public Figure {
	private:
		int mWidth;
		int mLength;
	public:
		int getWidth(int w) {
			return w;
		}
		void setWidth(int w) {
			mWidth = w;
		}
		int getLength(int l) {
			return l;
		}
		void setLength(int l) {
			mLength = l;
		}
		void print(int mWidth, int mLength) {
			for (int i = 1; i <= mWidth; ++i ) {
				for (int j = 1; j <= mLength; ++j) {
					std::cout << "o ";
				}
				std::cout << std::endl;
			}
		}

};

class Square: public Figure {
	private:
		int mSize;
	public:
		int getSize(int s) {
			return s;
		}
		void setSize(int s) {
			mSize = s;
		}
		void print(int mSize) {
			for (int i = 1; i <= mSize; ++i ) {
				for (int j = 1; j <= mSize; ++j) {
					std::cout << "o ";
				}
				std::cout << std::endl;
			}
		}
};

class Triangle: public Figure {
	private:
		int mSize;
	public:
		int getSize(int s) {
			return s;
		}
		void setSize(int s) {
			mSize = s;
		}
		void print(int mSize) {
			for (int i = 1; i <= mSize; ++i) {
				for (int j = 1; j <= i; ++j) {
					std::cout << "o ";
				}
				std::cout << std::endl;
			}
		}
};

int main() {
	Figure* rectangle = new Rectangle(4, 8);
	rectangle -> print();
	Figure* square = new Square(8);
	square -> print();
	Figure* triangle = new Triangle(8);
	triangle -> print();
	return 0;
}
