#include "ship.hpp"
#include <iostream>
Ship::Ship(ShipSize size)
{
    this->size = size;
    switch(size)
    {
        case SMALL:
            //setTexture("resources/small_ship.png");
            setColliderSize(30, 50);
            setHp(1);
            break;
        case MEDIUM:
            //setTexture("resources/medium_ship.png");
            setColliderSize(40, 60);
            setHp(2);
            break;
        case LARGE:
            //setTexture("resources/large_ship.png");
            setColliderSize(50, 70);
            setHp(100);
            break;
    }
}

void Ship::draw()
{
    Vector2 position = getPosition();
    switch(size)
    {
        case SMALL:
            DrawRectangle(position.x, position.y, 30, 50, RED);
            break;
        case MEDIUM:
            DrawRectangle(position.x, position.y, 40, 60, RED);
            break;
        case LARGE:
            DrawRectangle(position.x, position.y, 50, 70, RED);
            break;
    }
}

void Ship::impact()
{
    setHp(getHp() - 1);
    if(getHp() <= 0)
    {
        setActive(false);
    }
}
