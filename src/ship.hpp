#pragma once
#include <raylib.h>
#include "entity.hpp"
#include "impactable.hpp"

class Ship: public Impactable, public Entity{
    public:
        Ship();
        ~Ship();
        void draw();
        void impact();
    private:
        enum ShipSize {SMALL, MEDIUM, LARGE};
        ShipSize size;
};