#include "entity.hpp"

Entity::Entity()
{
    position = {0, 0};
    speed = {0, 0};
}

void Entity::update()
{
    move(speed.x, speed.y);
}

void Entity::draw()
{
    //DrawTexture(texture, position.x, position.y, WHITE);
}

void Entity::move(int x, int y)
{
    position.x += x;
    position.y += y;
}
void Entity::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}
void Entity::setSpeed(int x, int y)
{
    speed.x = x;
    speed.y = y;
}
void Entity::setTexture(const char* path)
{
    texture = LoadTexture(path);
}
void Entity::setHp(int hp)
{
    this->hp = hp;
}
Vector2 Entity::getPosition()
{
    return position;
}
Vector2 Entity::getSpeed()
{
    return speed;
}
Texture2D Entity::getTexture()
{
    return texture;
}
int Entity::getHp()
{
    return hp;
}
Entity::~Entity()
{
    UnloadTexture(texture);
}

void Entity::destroy()
{
    delete this;
}