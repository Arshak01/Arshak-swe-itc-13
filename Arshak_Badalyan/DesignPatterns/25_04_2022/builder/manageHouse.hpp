#include "./houseBuilder.hpp"

class ManageHouse{
private:
    Builder* builder;
public:
    void set_builder(Builder* builder);
    void buildHouse();
    void buildFullFeaturedHouse();
};

