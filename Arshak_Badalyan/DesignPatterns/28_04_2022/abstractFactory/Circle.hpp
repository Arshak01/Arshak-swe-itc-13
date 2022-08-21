#ifndef CIRCLE
#define CIRCLE

#include "./Shape.hpp"

class Circle :public Shape{
public:
    void drow();
};

class RoundedCircle :public Shape{
public:
    void drow();
};

#endif