#include <iostream>
#include "./RoundedShapeFactory.hpp"
#include "./Rectangle.hpp"
#include "./Square.hpp"
#include "./Circle.hpp"

Shape* RoundedShapeFactory::creatStandart(std::string shapeType){
    std::cout << "CreatStandart : \n\t\t";
    if(shapeType == "" ){
        return NULL;
    }else if(shapeType == "rectangle"){
        return new RoundedRectangle();
    }else if(shapeType == "square"){
        return new RoundedSquare();
    }else if(shapeType == "circle"){
        return new RoundedCircle();
    }
    return NULL;
}

Shape* RoundedShapeFactory::creatModern(std::string shapeType){
    std::cout << "CreatModern : \n\t\t";
    if(shapeType == "" ){
        return NULL;
    }else if(shapeType == "rectangle"){
        return new RoundedRectangle();
    }else if(shapeType == "square"){
        return new RoundedSquare();
    }else if(shapeType == "circle"){
        return new RoundedCircle();
    }
    return NULL;
}

Shape* RoundedShapeFactory::creatLuxury(std::string shapeType){
    std::cout << "CreatLuxury : \n\t\t";
    if(shapeType == "" ){
        return NULL;
    }else if(shapeType == "rectangle"){
        return new RoundedRectangle();
    }else if(shapeType == "square"){
        return new RoundedSquare();
    }else if(shapeType == "circle"){
        return new RoundedCircle();
    }
    return NULL;
}
