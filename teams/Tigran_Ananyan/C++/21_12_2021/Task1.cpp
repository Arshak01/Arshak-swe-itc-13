#include <iostream>

class Shape {
public:
    virtual void print() = 0;
};

class Rectangle : public Shape {
private:
    int length;
    int width;
public:
    Rectangle(int width, int length) {
        this->width = width;
        this->length = length;
    }
    void setWidth(int width) {
        this->width = width;
    }
    int getWidth() {
        return this->width;
    }
     void setLength(int length) {
        this->length = length;
    }
    int getLength() {
        return this->length;
    }
    void print() override {
        std::cout << "Rectangle:\n\n";
        for(int i = 1; i <= this->length; i++) {
            for(int j = 1; j <= this->width; j++) {
            std::cout << " * ";
            }
            std::cout << std::endl;
        }
    }
};

class Square : public Shape {
private:
    int side;
public:
    Square(int side) {
        this->side = side;    }
    void setSide(int side) {
        this->side = side;
    }
    int getSide() {
        return this->side;
    }
    void print() override {
        char sign = '*';
        std::cout << "\n\nSquare:\n\n";
        for(int i = 1; i <= this->side; i++) {
            for(int j = 1; j <= side; j++) {
                std::cout << " * ";
            }
            std::cout << std::endl;
        }
    }
};

class Triangle : public Shape {
private:
    int side;
public:
    Triangle(int side) {
        this->side = side;    }
    void setSide(int side) {
        this->side = side;
    }
    int getSide() {
        return this->side;
    }

    void print() override {
        std::cout << "\n\nTriangle:\n\n";
        for(int i = 0; i <= this->side; i++) {
            for(int j = 0; j <= i; j++) {
             std::cout << "* ";
            }
            std::cout << std::endl;
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
    delete rectangle;
    delete square;
    delete triangle;
    return 0;
}
