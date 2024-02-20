#include "entity.hpp"

Entity::Entity()
{
    position = {0, 0};
}

void Entity::update(){}
void Entity::draw(){}

void Entity::move(float x, float y)
{
    position.x += x;
    position.y += y;
}
void Entity::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
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

Texture2D Entity::getTexture()
{
    return texture;
}
int Entity::getHp()
{
    return hp;
}

void Entity::setEntityType(int entity_type)
{
    this->entity_type = entity_type;
}

int Entity::getEntityType()
{
    return entity_type;
}

void Entity::setActive(bool active)
{
    this->active = active;
}

bool Entity::isActive()
{
    return active;
}

Entity::~Entity()
{
    //UnloadTexture(texture);
}

void Entity::destroy()
{
    delete this;
}