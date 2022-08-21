#include "./proxyImage.hpp"
#include <iostream>

ProxyImage::ProxyImage(){};

ProxyImage::ProxyImage(std::string fileName){
    this->fileName = fileName;
};

void ProxyImage::display(){
    if(this->realImage == NULL){
        this->realImage = new RealImage(fileName);
    }
    realImage;
    std::cout << "Displaying " << this->fileName << std::endl;
};

