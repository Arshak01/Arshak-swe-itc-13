#include <iostream>

class Shape {
public:
    virtual void print() = 0;
};

class Rectangle: public Shape {
private:
    int mLength;
    int mWidth;
public:
    void setLength(int l) {
        mLength = l;
    }
    int getLength() {
        return mLength;
    }
    void setWidth(int w) {
        mWidth = w;
    }
    int getWidth() {
        return mWidth;
    }
    
    void print() {
        std::cout << "Rectangle:" << std::endl;
        for (int i = 0; i < mWidth; ++i) {
            for (int j = 0; j < mLength; ++j) {
                std::cout << " * " ;
            }
            std::cout << std::endl;
        }
    }

    Rectangle(int l = 0, int w = 0) {
        mLength = l;
        mWidth = w;
    }
};

class Square: public Shape {
private:
    int mSide;
public:
    void setSide(int s) {
        mSide = s;
    }
    int getSide() {
        return mSide;
    }
    void print() {
        std::cout << "Square:" << std::endl;
        for (int i = 0; i < mSide; ++i) {
            for (int j = 0; j < mSide; ++j) {
                std::cout << " * " ;
            }
            std::cout << std::endl;
        }
    }

    Square(int s = 0) {
        mSide = s;
    }
};

class Triangle: public Shape {
private:
    int mSide;
public:
    void setSide(int s) {
        mSide = s;
    }
    int getSide() {
        return mSide;
    }
    void print() {
        std::cout << "Triangle" << std::endl;
        for (int i = 0; i < mSide; ++i) {
            for (int j = 0; j < i; ++j) {
                std::cout << " * " ;
            }
            std::cout << std::endl;
        }
    }

    Triangle(int s = 0){
        mSide = s;
    }
};

int main() {
    Shape *rect = new Rectangle(5, 6);
    rect->print();
    Shape *square = new Square(3);
    square->print();
    Shape *triangle = new Triangle(5);
    triangle->print();

    delete rect;
    delete square;
    delete triangle; 

    return 0;
}
