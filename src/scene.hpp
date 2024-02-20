#pragma once
#include <raylib.h>
#include <vector>
#include "entity.hpp"
class Scene{
    public:
    Scene();
    virtual void draw();
    virtual void update();
    void destroy();
    void addEntity(Entity* entity);
    void setBackgroundColor(Color color);
    Color getBackgroundColor();
    std::vector<Entity*> getEntitiesByType(int entity_type);
    std::vector<Entity*> getEntities();
    private:
    void manageCollisions();
    void manageCollisionsPll(unsigned int lo, unsigned int hi, unsigned int depth);
    void destroyInactiveEntities();
    std::vector<Entity*> entities;
    Color backgroundColor = GetColor(0x36c5f400);
};