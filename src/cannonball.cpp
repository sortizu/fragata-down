#include "cannonball.hpp"

Cannonball::Cannonball()
{
    //setTexture("assets/cannonball.png");
    setColliderSize(10, 10);
    setColliderOffset(-5, -5);
}

void Cannonball::draw()
{
    Vector2 position = getPosition();
    DrawCircle(position.x, position.y, 5, BLACK);
    DrawPixel(position.x+2, position.y+2, WHITE);
}

void Cannonball::update()
{
    PhysicsEntity::update();
}
