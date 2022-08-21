#include "./realImage.hpp"


RealImage::RealImage(std::string fileName){
    this->fileName = fileName;
};

void RealImage::display(){
    std::cout << "Displaying " << this->fileName << std::endl;
};

void RealImage::loadFromDisk(std::string fileName){
    std::cout << "Loading " << this->fileName << std::endl;
};
