#include <iostream>

class Shape {
   public:
      virtual void print() = 0;      
};

class Rectangle: public Shape {
private:
      int width ;
      int height ;
public:
	Rectangle(){
	}
	Rectangle (int width, int height ) {
		this -> width = width;
		this -> height = height;
	}
	void setWidth(int width) {
		this -> width = width;
      	}
      	int getWidth() { 
		return this -> width;
      	}
      	void setHeight(int height) {
         	this -> height = height;
      	}
      	int getHeight() {
		return this -> height;
      	}
	
	void print() override { 
		std::cout << "Rectangle\n" ;
		for(int i = 1; i <= getWidth(); i++) {
			for (int j = 1; j <= getHeight(); j++){
        			std::cout << " ▪";
    			}
    		std::cout << "\n";
		} 
      } 
};

class Square: public Shape {
private:
	int side;
public:
	Square(int side) {
		this -> side = side;
	}
	void setSide(int side) {
         	this -> side = side;
	}
	int getSide() {
		return this -> side;
	}
	void print() { 
		std::cout << "Square\n" ;
		for (int i = 1; i <= getSide(); i++) {
			for (int j = 1; j <= getSide(); j++) {
            			std::cout << " ◼";; 
            		}
            		std::cout << "\n";
      		}
      	}
};

class Trianagle: public Shape {
private:
	int side;
public:
	Trianagle (int side) {
		this -> side = side;
	}
	void setSide(int side) {
         	this -> side = side;
	}
	int getSide() {
		return this -> side;
	}
	void print() { 
		std::cout << "Trianagle\n" ;
		for (int i = 1; i <= getSide(); i++) {
			for (int j = 1; j <= i; j++) {
            			std::cout << " ▶ ";; 
            		}
            		std::cout << "\n";
      		}
      	}
};

int main() {

	Shape *rectangle = new Rectangle(3,5);
	Rectangle *rec = new Rectangle(2,2);
	rectangle -> print();
	rec->setWidth(5);
	rec -> print();
	Shape *square = new Square(5);
	square -> print();
	Shape *triangle = new Trianagle(5);
	triangle -> print();
	return 0;
}


