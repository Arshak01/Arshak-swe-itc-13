#include <iostream>
class Shape{
	public:
		virtual void print() {};
};

class Rectangle : public Shape {
	private:
		int mLength;
		int mWidth;
	public:
		Rectangle(int length, int width) {
			mLength = length;
			mWidth = width;
		}
		int getLength() {
			return mLength;
		}
		void setLength(int length) {
			mLength = length;
		}
		void print() {
			std::cout << "Rectangle:\n";
			for (int i = 0; i < mLength; ++i) {
				for(int j = 0; j < mWidth; ++j)
					std::cout << "* ";
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
};

class Square : public Shape {
	private:
		int mSide;
	public:
		Square(int side) {
			mSide = side;
		}
		int getSide() {
			return mSide;
		}
		void setSide(int side) {
			mSide = side;
		}
		void print() {
			std::cout << "Square:\n";
			for (int i = 0; i < mSide; ++i) {
				for (int j = 0; j < mSide; ++j)
					std::cout << "* ";
				std::cout <<std::endl;
			}
			std::cout << std::endl;
		}
};

class Triangle : public Shape {
	private:
		int mSide;
	public:
		Triangle(int side) {
			mSide = side;
		}
		int  getSide() {
			return mSide;
		}
		void setSide(int side) {
			mSide = side;
		}
		void print() {
			std::cout << "Triangle:\n";
			for (int i = 0; i <= mSide; ++i) {
				for (int j = 0; j <= i; ++j)
					std::cout << "* ";
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
};

int main() {
	Shape *rectangle = new Rectangle(5,6);
	rectangle->print();
	Shape *square = new Square(3);
	square->print();
	Shape *triangle = new Triangle(5);
	triangle->print();
	return 0;
}
