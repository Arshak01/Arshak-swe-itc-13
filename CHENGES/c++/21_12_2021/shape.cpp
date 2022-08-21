#include <iostream>

class Shape {
	public:	
		virtual void print() = 0;		
};

class Rectangle: public Shape {
	
	private:
		float length;
	        float width;	
	
	public:
		Rectangle(float length, float width) {
			setLength(length);
			setWidth(width);
		}

		void setLength(float length) {
         		this-> length = length;
      		}
		float getLength() {
         		return this-> length;
      		}

		void setWidth(float width) {
			this-> width = width;
      		}	
		float getWidth() {
			return this-> width;
      		}

		void print() {
			std::cout << "**** Rectangle ****\n" << std::endl;
			setRectangle();
			std::cout << "\n" << std::endl;
		}

		void setRectangle() {
			for(int i = 0; i < getLength(); ++i) {
				for(int j = 0; j < getWidth(); ++j) {
					std::cout << "* ";
				}
				std::cout << std::endl;
			}
		}
};

class Square: public Shape {
	
	private:
		float side;
	
	public:
		Square(float side) {
			setSide(side);
		}

		void setSide(float side) {
         		this-> side = side;
      		}
		float getSide() {
         		return this-> side;
      		}

		void print() {
			std::cout << "**** Square ****\n" << std::endl;
			setSquare();
			std::cout << "\n" << std::endl;
		}

		void setSquare() {
			for(int i = 0; i < getSide(); ++i) {
				for(int j = 0; j < getSide(); ++j) {
					std::cout << "* ";
				}
				std::cout << std::endl;
			}
		}
};

class Triangle: public Shape {

	private:
		float side;
	public:
		Triangle(float side) {
			setSide(side);
		}

		void setSide(float side) {
         		this-> side = side;
      		}

		float getSide() {
         		return this-> side;
      		}

		void print() {
			std::cout << "**** Triangle ****\n" << std::endl;
			setTriangle();
			std::cout << "\n" << std::endl;
		}

		void setTriangle() {
			for(int i = 0; i < getSide(); ++i) {
				for(int j = 0; j <= i; ++j) {
					std::cout << "* ";
				}
				std::cout << std::endl;
			}
		}
};

int main() {

	Shape *rectangle = new Rectangle(6, 5);
	rectangle->print();

	Shape *square = new Square(3);
	square->print();

	Shape *triangle = new Triangle(5);
	triangle->print();
	
	return 0;
}
