#include <iostream>

class Shape {
	public:
		virtual void print() = 0;
};

class Rectangle: public Shape {
	private:
		int height;
		int width;
	public:
		void setter(int h, int w) {
			this -> height = h;
			this -> width = w;
		}
		int getter() {
			return height, width;
		}
		Rectangle(int h, int w) {
			this-> height = h;
			this-> width = w;	
		}
		void print() {
			std::cout << "\nRectangle:\n\n";
			for (int i = 0; i < width; ++i) {
				for (int j = 0; j < height; ++j) {
					std::cout << "* ";
				}
				std::cout << "\n";
			}
		}
};

class Triangle: public Shape {
	private:
		int side;
	public:
		void setter(int s) {
			this -> side = s;
		}
		int getter() {
			return side;
		}
		Triangle(int s) {
			this-> side = s;
		}
		void print() {
			std::cout << "\nTriangle:\n\n";
			for (int i = 1; i <= side; ++i) {
				for (int j = 1; j <= i; ++j) {
					std::cout << "* ";
				}
				std::cout << "\n";
			}
		}
};

class Square: public Shape {
	private:
		int side;
	public:
		void setter(int s) {
			this -> side = s;
		}
		int getter() {
			return side;
		}
		Square(int s) {
			this-> side = s;
		}
		void print() {
			std::cout << "\nSquare:\n\n";
			for (int i = 0; i < side; ++i) {
				for (int j = 0; j < side; ++j) {
					std::cout << "* ";
				}
				std::cout << "\n";
			}
		}
};

int main() {

	Shape *rectangle = new Rectangle(5, 6);
	rectangle->print();
	Shape *square = new Square(3);
	square->print();
	Shape *triangle = new Triangle(5);
	triangle->print();	
	return 0;
}

