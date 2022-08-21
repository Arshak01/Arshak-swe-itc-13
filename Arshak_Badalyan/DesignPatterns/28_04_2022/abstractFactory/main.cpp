#include <iostream>
#include "./FactoryProducer.hpp"
#include "./AbstractFactory.hpp"
#include "./ShapeFactory.hpp"

int main(){
    AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);
    Shape* shape1 = shapeFactory1->creatModern("circle");
    shape1->drow();

    AbstractFactory* shapeFactory2 = FactoryProducer::getFactory(false);
    Shape* shape2 = shapeFactory2->creatLuxury("rectangle");
    shape2->drow();

    return 0;
}

