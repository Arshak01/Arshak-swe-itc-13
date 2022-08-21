#include "./house.hpp"
#include "./builder.hpp"


class HouseBuilder: public Builder {
private:
    House* house;

public:
    HouseBuilder();
    ~HouseBuilder();
    void Reset();
    void buildWalls();
    void buildDoors();
    void buildWindows();
    void buildRoof();
    void buildGarage();
    void buildBasement();
    void buildInterior();
    House* getHouse();

};