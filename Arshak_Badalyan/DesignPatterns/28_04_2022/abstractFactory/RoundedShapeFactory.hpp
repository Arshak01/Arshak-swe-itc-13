#ifndef ROUNDED_SHAPE_FACTORY
#define ROUNDED_SHAPE_FACTORY

#include <iostream>
#include "./Shape.hpp"
#include "./AbstractFactory.hpp"

class RoundedShapeFactory: public AbstractFactory {
public:
    Shape* creatStandart(std::string shapeType);
    Shape* creatModern(std::string shapeType);
    Shape* creatLuxury(std::string shapeType);
};

#endif