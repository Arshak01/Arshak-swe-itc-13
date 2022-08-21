#include <iostream>
#include "./ShapeFactory.hpp"

int main(){
    ShapeFactory* shapeFactory = new ShapeFactory();
    Shape* shape1 = shapeFactory->getShape("circle");
    Shape* shape2 = shapeFactory->getShape("rectangle");
    shape1->drow();
    shape2->drow();

    return 0;
}

