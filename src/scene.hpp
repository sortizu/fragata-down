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
    std::vector<Entity*> getEntities();
    private:
    void destroyInactiveEntities();
    std::vector<Entity*> entities;
    Color backgroundColor = GetColor(0x36c5f400);
};