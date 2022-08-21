#include "./manageHouseBuilder.hpp"


void manageHouseBuilder(ManageHouse& manageHouse){
    HouseBuilder* builder = new HouseBuilder();
    manageHouse.set_builder(builder);
    std::cout << "Standard house:\n";
    manageHouse.buildHouse();

    House* house= builder-> getHouse();
    house->houseBuilderList();
    delete house;

    std::cout << "Standard full featured house:\n";
    manageHouse.buildFullFeaturedHouse();

    house= builder->getHouse();
    house->houseBuilderList();

    delete house;
    delete builder;
}