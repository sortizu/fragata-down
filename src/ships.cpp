#include "ship.hpp"

class SmallShip: public Ship{
    public:
        SmallShip(){
            //setTexture("resources/small_ship.png");
            setHp(1);
        };
};

class MediumShip: public Ship{
    public:
        MediumShip(){
            //setTexture("resources/medium_ship.png");
            setHp(2);
        };
};
class LargeShip: public Ship{
    public:
        LargeShip(){
            //setTexture("resources/large_ship.png");
            setHp(3);
        };
};