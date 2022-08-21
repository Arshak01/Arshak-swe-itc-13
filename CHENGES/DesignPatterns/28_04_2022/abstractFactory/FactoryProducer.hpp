#ifndef FACTORY_PRODUCER
#define FACTORY_PRODUCER

#include <iostream>
#include "./AbstractFactory.hpp"

class FactoryProducer {
public:
    static AbstractFactory* getFactory(bool type);
};

#endif