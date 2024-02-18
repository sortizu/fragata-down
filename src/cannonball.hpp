#pragma once
#include "physics_entity.hpp"
class Cannonball : public PhysicsEntity
{ 
    public:
        Cannonball();
        void draw() override;
        void update() override;
    private:
        Vector2 targetPosition;
};