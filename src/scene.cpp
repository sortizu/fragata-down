#include "scene.hpp"
#include <iostream>
#include <future>
#include "physics_entity.hpp"

double startTime = 0.0;
double endTime = 0.0;
double timer = 0.0;
double executionTime = 0.0;
double executionTimeAc = 0.0;
double averageExecutionTime = 0.0;
int executionCounter = 0;

Scene::Scene(){
    std::thread physicsThread(&Scene::physicsUpdate, this);
}

void Scene::draw()
{
    ClearBackground(backgroundColor);
    for(int i = 0; i < int(entities.size()); i++)
    {
        entities[i]->draw();
    }
    DrawText(("Collision check time: " + std::to_string(executionTime) + " seconds.").c_str(), 10, GetScreenHeight()-40, 20, WHITE);
    DrawText(("Average collision check time: " + std::to_string(averageExecutionTime) + " seconds.").c_str(), 10, GetScreenHeight()-20, 20, WHITE);
}

void Scene::update()
{
    for(int i = 0; i < int(entities.size()); i++)
    {
        entities[i]->update();
    }

    //manageCollisionsPll(0, entities.size(), 0);
}




void Scene::physicsUpdate()
{
    while (true)
    {
        manageCollisions();
        destroyInactiveEntities();
    }
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

std::vector<Entity*> Scene::getEntitiesByType(int entity_type)
{
    std::vector<Entity*> new_entities;
    for(int i = 0; i < int(entities.size()); i++)
    {
        if(entities[i]->getEntityType() == entity_type)
        {
            new_entities.push_back(entities[i]);
        }
    }
    return new_entities;
}

std::vector<Entity*> Scene::getEntities()
{
    return entities;
}

void Scene::manageCollisions()
{
    for (unsigned int i = 0; i < int(entities.size()); i++)
    { 
        PhysicsEntity *physicsEntity = dynamic_cast<PhysicsEntity*>(entities[i]);
        if (physicsEntity == nullptr)
            continue;
        for (int j = 0; j < int(entities.size()); j++)
        {
            if(i == j)
                continue;
            PhysicsEntity *otherEntity = dynamic_cast<PhysicsEntity*>(entities[j]);
            if (otherEntity != nullptr && physicsEntity->checkCollision(otherEntity))
            {
                physicsEntity->onCollision(otherEntity);
            }
        }
    }
}

// This function checks if a physics entity is colliding with another physics entity
// in that case, it calls the onCollision method on both entities,
// it also applies divide and conquer to try to parallelize the process
void Scene::manageCollisionsPll(unsigned int lo, unsigned int hi, unsigned int depth){
    if(depth>3)
    {
        for (unsigned int i = lo; i < hi; i++)
        { 
            PhysicsEntity *physicsEntity = dynamic_cast<PhysicsEntity*>(entities[i]);
            if (physicsEntity == nullptr)
                continue;
            for (int j = 0; j < int(entities.size()); j++)
            {
                if(i == j)
                    continue;
                PhysicsEntity *otherEntity = dynamic_cast<PhysicsEntity*>(entities[j]);
                if (otherEntity != nullptr && physicsEntity->checkCollision(otherEntity))
                {
                    physicsEntity->onCollision(otherEntity);
                }
            }
        }
    }
    else
    {
        if(depth == 0)
            startTime = GetTime();
        auto mid = (lo+hi)/2;
        auto left = std::async(std::launch::async, &Scene::manageCollisionsPll, this, lo, mid, depth+1);
        auto right = std::async(std::launch::async, &Scene::manageCollisionsPll, this, mid, hi, depth+1);
        left.get();
        right.get();
    }
    if(depth == 0)
        {
            executionCounter++;
            endTime = GetTime();
            executionTime = endTime - startTime;
            executionTimeAc += executionTime;
            timer += GetFrameTime();

            if(timer > 0.5)
            {
                averageExecutionTime = executionTimeAc / executionCounter;
                executionCounter=0;
                executionTimeAc=0;
                timer = 0.0;
            }
        }
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
