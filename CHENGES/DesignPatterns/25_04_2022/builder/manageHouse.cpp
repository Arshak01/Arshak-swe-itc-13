#include "./manageHouse.hpp"

void ManageHouse::set_builder(Builder* builder){
    this->builder = builder;
}

void ManageHouse::buildHouse(){
    this->builder->buildWalls();
    this->builder->buildRoof();
    this->builder->buildWindows();
    this->builder->buildDoors();
}

void ManageHouse::ManageHouse::buildFullFeaturedHouse(){
    this->builder->buildWalls();
    this->builder->buildRoof();
    this->builder->buildWindows();
    this->builder->buildGarage();
    this->builder->buildGarage();
    this->builder->buildBasement();
    this->builder->buildInterior();
}
