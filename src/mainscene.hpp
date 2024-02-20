#pragma once
#include "scene.hpp"

class MainScene : public Scene
{
    public:
        MainScene();
        void draw() override;
        void update() override;
        enum EntityType
        {
            SHIP,
            CANNONBALL
        };
    private:
        void spawnShips();
        void deactiveShips();
        void deactiveCannonballs();
        void manageInput();
        double spawnShipTimer = 0;
        double spawningTime = 3;
};