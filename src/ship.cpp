#include "ship.hpp"

Ship::Ship()
{
}

void Ship::draw()
{
    Vector2 position = getPosition();
    DrawRectangle(position.x, position.y, 50, 50, RED);
}

void Ship::impact()
{
    setHp(getHp() - 1);
    if(getHp() <= 0)
    {
        destroy();
    }
}
