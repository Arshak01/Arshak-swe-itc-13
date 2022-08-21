#ifndef ABSTRACT_FACTORY
#define ABSTRACT_FACTORY

#include <iostream>
#include "./Shape.hpp"

struct AbstractFactory {
public:
    virtual Shape* creatModern(std::string shapeType) = 0;
    virtual Shape* creatStandart(std::string shapeType) = 0;
    virtual Shape* creatLuxury(std::string shapeType) = 0;
};

#endif