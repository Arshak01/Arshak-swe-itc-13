struct Builder{
public:
    virtual void buildWalls() = 0;
    virtual void buildDoors() = 0;
    virtual void buildWindows() = 0;
    virtual void buildRoof() = 0;
    virtual void buildGarage() = 0;
    virtual void buildBasement() = 0;
    virtual void buildInterior() = 0;
};