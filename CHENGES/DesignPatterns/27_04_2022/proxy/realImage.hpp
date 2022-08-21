#ifndef REAL_IMAGE
#define REAL_IMAGE

#include <iostream>
#include "./image.hpp"

class RealImage :public Image{
private:
    std::string fileName;
public:
    RealImage(std::string fileName);
    void display();
    void loadFromDisk(std::string fileName);
};
#endif