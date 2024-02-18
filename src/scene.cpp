#include "scene.hpp"
#include <iostream>

Scene::Scene(){}

void Scene::draw()
{
    ClearBackground(backgroundColor);
    for(int i = 0; i < int(entities.size()); i++)
    {
        entities[i]->draw();
    }
}

void Scene::update()
{
    for(int i = 0; i < int(entities.size()); i++)
    {
        entities[i]->update();
    }
    destroyInactiveEntities();
}

void Scene::destroy()
{
    for(int i = 0; i < int(entities.size()); i++)
    {
        delete entities[i];
    }
    delete this;
}

void Scene::addEntity(Entity *entity)
{
    entities.push_back(entity);
}

void Scene::setBackgroundColor(Color color)
{
    backgroundColor = color;
}

Color Scene::getBackgroundColor()
{
    return backgroundColor;
}

std::vector<Entity*> Scene::getEntities()
{
    return entities;
}

void Scene::destroyInactiveEntities()
{
    for(int i = 0; i < int(entities.size()); i++)
    {
        if(!entities[i]->isActive())
        {
            Entity *entity = entities[i];
            entities.erase(entities.begin() + i);
            entity->destroy();
        }
    }
}
