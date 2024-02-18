#pragma once
#include <raylib.h>
#include "physics_entity.hpp"
#include "impactable.hpp"

enum ShipSize {SMALL, MEDIUM, LARGE};

class Ship: public PhysicsEntity, public Impactable{
    public:
        Ship(ShipSize size);
        void draw() override;
        void impact() override;
    private:
        ShipSize size;
};