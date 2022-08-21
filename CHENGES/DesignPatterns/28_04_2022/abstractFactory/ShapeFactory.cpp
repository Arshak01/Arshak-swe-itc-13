#include <iostream>
#include "./ShapeFactory.hpp"
#include "./Rectangle.hpp"
#include "./Square.hpp"
#include "./Circle.hpp"

Shape* ShapeFactory::creatStandart(std::string shapeType){
    std::cout << "CreatStandart : \n\t\t";
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

Shape* ShapeFactory::creatModern(std::string shapeType){
    std::cout << "CreatModern : \n\t\t";
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

Shape* ShapeFactory::creatLuxury(std::string shapeType){
    std::cout << "CreatLuxury : \n\t\t";
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

