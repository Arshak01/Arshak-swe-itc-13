cmake_minimum_required(VERSION 3.10)
project(ABSTRACT_FACTORY)
set(ABSTRACT_FACTORY AbstractFactory.hpp)
set(SHAPE Shape.hpp)
set(SQUARE Square.cpp)
set(CIRCLE Circle.cpp)
set(RECTANGLE Rectangle.cpp)
set(SHAPE_FACTORY ShapeFactory.cpp)
set(ROUNDED_SHAPE_FACTORY RoundedShapeFactory.cpp)
set(FACTORY_PRODUCER FactoryProducer.cpp)
set(MAIN main.cpp)

add_executable(main.out  ${ABSTRACT_FACTORY} ${SHAPE} ${SQUARE} ${CIRCLE} ${RECTANGLE}
 ${SHAPE_FACTORY} ${ROUNDED_SHAPE_FACTORY} ${FACTORY_PRODUCER} ${MAIN} )
