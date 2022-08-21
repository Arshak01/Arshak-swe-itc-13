#ifndef SHAPE_FACTORY
#define SHAPE_FACTORY

#include "./Shape.hpp"
#include "./ShapeFactory.hpp"
#include "./AbstractFactory.hpp"

class ShapeFactory: public AbstractFactory {
public:
    Shape* creatStandart(std::string shapeType);
    Shape* creatModern(std::string shapeType);
    Shape* creatLuxury(std::string shapeType);

};

#endif