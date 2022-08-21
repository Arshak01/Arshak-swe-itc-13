#ifndef PROXY_IMAGE
#define PROXY_IMAGE

#include <iostream>
#include "./image.hpp"
#include "./realImage.hpp"

class ProxyImage :public Image{
private:
    std::string fileName;
    RealImage* realImage;
public:
    ProxyImage();
    ProxyImage(std::string fileName);
    void display();
};

#endif