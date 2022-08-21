#include <iostream>

class Shape {
public:
    virtual void print() = 0;
};

class Rectangle : public Shape {
private:
    int length = 0;
    int width = 0;
public:
    Rectangle() {}

    Rectangle(int length, int width) {
        this->length = length;
        this->width = width;
    }

    int getLength() {
        return this->length;
    }

    void setLength(int length) {
        this->length = length;
    }

    int getWidth() {
        return this->width;
    }

    void setWidth(int width) {
        this->width = width;
    }

    void print() {
        std::cout << "Rectangle" << std::endl;
        for (int i = 0; i < getWidth(); ++i) {
            for (int j = 0; j < getLength(); ++j) {
                std::cout << " * ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

class Square : public Shape {
private:
    int side;
public:
    Square() {}

    Square(int side) {
        this->side = side;
    }

    void setSide(int side) {
        this->side = side;
    }

    int getSide() {
        return this->side;
    }

    void print() {
        std::cout << "Square" << std::endl;
        for (int i = 0; i < getSide(); ++i) {
            for (int j = 0; j < getSide(); ++j) {
                std::cout << " * ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

class Triangle : public Shape {
private:
    int side;
public:
    Triangle() {}

    Triangle(int side) {
        this->side = side;
    }

    int getSide() {
        return this->side;
    }

    void setSide(int side) {
        this->side = side;
    }

    void print() {
        std::cout << "Triangle" << std::endl;
        for (int i = 0; i < getSide(); ++i) {
            for (int j = 0; j <= i; ++j) {
                std::cout << " * ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
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