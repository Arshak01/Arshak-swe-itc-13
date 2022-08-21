#ifndef RECTANGLE
#define RECTANGLE

#include "./Shape.hpp"

class Rectangle :public Shape{
public:
    void drow();
};

class RoundedRectangle :public Shape{
public:
    void drow();
};

#endif