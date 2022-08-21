#include <iostream>
#include "./ShapeFactory.hpp"
#include "./Rectangle.hpp"
#include "./Square.hpp"
#include "./Circle.hpp"

Shape* ShapeFactory::getShape(std::string shapeType){
    if(shapeType == "" ){
        return NULL;
    }else if(shapeType == "rectangle"){
        return new Rectangle();
    }else if(shapeType == "square"){
        return new Square();
    }else if(shapeType == "circle"){
        return new Circle();
    }
    return NULL;
}
