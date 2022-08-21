#include <iostream>

class Shape {
public:
	virtual void print()=0;
};

class Rectangle: public Shape {
private:
	int mLength;
	int mWidth;
public:
	void setLength(int lCount) {
		mLength = lCount;
	}
	int getLength() {
		return mLength;
	}	
	void setWidth(int wCount) {
		mWidth = wCount;
	}
	int getWidth() {
		return mWidth;
	}
	Rectangle(int RecCount1, int RecCount2) {
		mLength = RecCount1;
		mWidth = RecCount2;
	}
	void print() {
		for(int i = 1; i <= mWidth; ++i) {
			for(int j = 1; j <= mLength; ++j) {
				std::cout << "*";
			}
			std::cout << std::endl;
		}
	}
};

class Square: public Shape {
private:
	int mSide;
public:
	void setSide(int sideCount) {
		mSide = sideCount;
	}
	int getSide() {
		return mSide;
	}
	Square(int SquareCount){
		mSide = SquareCount;
	}
	void print() {
			for(int i = 1; i <= mSide; ++i) {
				for(int j = 1; j <= mSide; ++j) {
					std::cout << "*";
				}
				std::cout << std::endl;
			}
	}
};

class Triangle: public Shape {
private:
	int mSide1;
public:
	void setSide1(int sCount){
		mSide1 = sCount;
	}
	int getSide1() {
		return mSide1;
	}
	Triangle(int trCount) {
		mSide1 = trCount;
	}
	void print() {
		for(int i = 1; i <= mSide1; ++i) {
			for(int j = 1; j <= i; ++j) {
					std::cout << "*"; 
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	std::cout << "Rectangle:" << std::endl;
	Shape *rectangle = new Rectangle(10,5);
	rectangle->print();
	std::cout << "=================" << std::endl;
	
	std::cout << "Square:" << std::endl;
	Shape *square = new Square(3);
	square->print();
	std::cout << "=================" << std::endl;

	std::cout << "Triangle:" << std::endl;
	Shape *triangle = new Triangle(4);
	triangle->print();
	
	delete rectangle;
	delete square;
	delete triangle;

	return 0;
}
