#ifndef SHAPEFACTORY
#define SHAPEFACTORY

#include "./Shape.hpp"

class ShapeFactory{
public:
    Shape* getShape(std::string shapeType);
};

#endif