#include <iostream>
#include "./builder/manageHouseBuilder.hpp"

int main(){
    ManageHouse* manageHouse= new ManageHouse();
    manageHouseBuilder(*manageHouse);
    delete manageHouse;
    return 0;
}
