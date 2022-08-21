#include <iostream>
#include "./proxy/image.hpp"
#include "./proxy/proxyImage.hpp"

int main(){
    Image* image = new ProxyImage();
    image->display();
    return 0;
}

