#include <iostream>
#include "./FactoryProducer.hpp"
#include "./ShapeFactory.hpp"
#include "./RoundedShapeFactory.hpp"


AbstractFactory* FactoryProducer::getFactory(bool type){
    if(type){
        std::cout << "RoundedShapeFactory : \n\t";
        return new RoundedShapeFactory();
    }else{
        std::cout << "ShapeFactory : \n\t";
        return new ShapeFactory();
    }
}
