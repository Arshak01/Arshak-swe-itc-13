#include <iostream>

class Shape {
public:
    virtual void print() = 0;
    //To avoid code repeating
    void printRow(int row) {
        std::cout << "\t";
        for(int i = 0; i < row; ++i) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
};

class Rectangle : public Shape {
private:
    int length;
    int width;

public:
    Rectangle(int length, int width) {
        this->length = length;
        this->width = width;
    }
    void print() {
        std::cout << "Rectangle:" << std::endl;
        for(int i = 0; i < this->width; ++i) {
            printRow(this->length);
        }
    }
    void setLength(int length) {
        this->length = length;
    }
    int getLength() {
        return this->length;
    }
    void setWidth(int width) {
        this->width = width;
    }
    int getWidth() {
        return this->width;
    }
};

class Square : public Shape {
private:
    int side;

public:
    Square(int side) {
        this->side = side;
    }
    void print() {
        std::cout << "Square:" << std::endl;
        for(int i = 0; i < this->side; ++i) {
            printRow(this->side);
        }
    }
    void setSide(int side) {
        this->side = side;
    }
    int getSide() {
        return this->side;
    }
};

class Triangle : public Shape {
private:
    int rows;
public:
    Triangle(int rows) {
        this->rows = rows;
    }
    void print() {
        std::cout << "Triangle:" << std::endl;
        for(int i = this->rows - 1; i >= 0; --i) {
            printRow(this->rows - i);
        }
    }
    void setRows(int rows) {
        this->rows = rows;
    }
    int getRows() {
        return this->rows;
    }
};


int main() {
    Shape *rectangle = new Rectangle(5,6);
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
