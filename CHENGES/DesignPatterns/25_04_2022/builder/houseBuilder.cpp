#include "./houseBuilder.hpp"

HouseBuilder::HouseBuilder(){
    this->Reset();
}

HouseBuilder::~HouseBuilder(){
    delete house;
}

void HouseBuilder::Reset(){
    this->house= new House();
}

void HouseBuilder::buildWalls(){
    this->house->parts.push_back("Walls");
};

void HouseBuilder::buildDoors(){
    this->house->parts.push_back("Doors");
};

void HouseBuilder::buildWindows(){
    this->house->parts.push_back("Windows");
};

void HouseBuilder::buildRoof(){
    this->house->parts.push_back("Roof");
};

void HouseBuilder::buildGarage(){
    this->house->parts.push_back("Garage");
};

void HouseBuilder::buildBasement(){
    this->house->parts.push_back("Basement");
};

void HouseBuilder::buildInterior(){
    this->house->parts.push_back("Interior");
};

House* HouseBuilder::getHouse() {
    House* result = this->house;
    this->Reset();
    return result;
}
