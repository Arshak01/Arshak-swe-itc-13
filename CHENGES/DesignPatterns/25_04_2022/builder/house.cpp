#include "./house.hpp"

void House::houseBuilderList()const{
    std::cout << "House's parts: ";
    for (auto p : parts){
        if(p == parts.back()){
            std::cout << p;
        }else{
            std::cout << p << ", ";
        }
    }
    std::cout << "\n\n";
}
