#include "mainscene.hpp"
#include "ship.hpp"
#include <iostream>
#include "cannonball.hpp"


MainScene::MainScene()
{
    // Calls to the parent constructor
    Scene();
}

void MainScene::update()
{
    Scene::update();
    manageInput();
    if (GetTime()-spawnShipTimer > spawningTime)
    {
        spawnShips();
        spawnShipTimer = GetTime();
    }
    manageCannonCollisions();
    deactiveShips();
    deactiveCannonballs();
}
void MainScene::draw()
{
    Scene::draw();
    // Show fps
    DrawText(("FPS: " + std::to_string(GetFPS())).c_str(), GetScreenWidth()-100, 10, 20, WHITE);
}

void MainScene::spawnShips()
{
    int randomNum = GetRandomValue(1, 5);
    for (int i = 0; i < randomNum; i++)
    {
        ShipSize size = SMALL;
        switch (GetRandomValue(1, 3))
        {
            case 2:
                size = MEDIUM;
                break;
            case 3:
                size = LARGE;
                break;
        }
        Ship *ship = new Ship(size);
        ship -> setPosition(GetRandomValue(0,GetScreenWidth()), GetRandomValue(GetScreenHeight(),GetScreenHeight()*2));
        ship -> setVelocity(0, GetRandomValue(-40,-60)*GetFrameTime());
        addEntity(ship);
    }
}
void MainScene::deactiveShips()
{
    std::vector<Entity*> entities = getEntities();
    int shipCount = 0;
    for (int i = 0; i < int(entities.size()); i++)
    {
        // Checks if the entity is an instance of Ship
        if (dynamic_cast<Ship*>(entities[i]))
        {
            shipCount++;
            if (entities[i]->getPosition().y < 0)
            {
                entities[i]->setActive(false);
            }
        }
    }
    // Shows the number of ships in the screen
    std::string shipCountStr = std::to_string(shipCount);
    DrawText(("Ship count: " + shipCountStr).c_str(), 10, 10, 20, WHITE);
}

void MainScene::deactiveCannonballs()
{
    std::vector<Entity*> entities = getEntities();
    for (int i = 0; i < int(entities.size()); i++)
    {
        // Checks if the entity is an instance of Cannonball
        if (dynamic_cast<Cannonball*>(entities[i]))
        {
            if (entities[i]->getPosition().y > GetScreenHeight())
            {
                entities[i]->setActive(false);
            }
        }
    }
}

void MainScene::manageCannonCollisions()
{
    std::vector<Entity*> entities = getEntities();
    for (int i = 0; i < int(entities.size()); i++)
    {
        if (dynamic_cast<Cannonball*>(entities[i]))
        {
            PhysicsEntity *physicsEntity = dynamic_cast<PhysicsEntity*>(entities[i]);
            for (int j = 0; j < int(entities.size()); j++)
            {
                // Checks if the entity is an instance of Impactable and PhysicsEntity
                if (dynamic_cast<Impactable*>(entities[j]) && dynamic_cast<PhysicsEntity*>(entities[j]))
                {
                    
                    if(physicsEntity->checkCollision(dynamic_cast<PhysicsEntity*>(entities[j])))
                    {
                        Impactable *impactable = dynamic_cast<Impactable*>(entities[j]);
                        impactable->impact();
                        entities[i]->setActive(false);
                    }
                }
            }
        }
    }
}

void MainScene::manageInput()
{
    // Use the mouse position to shoot a cannonball
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Cannonball *cannonball = new Cannonball();
        cannonball -> setPosition(GetMousePosition().x, 0);
        cannonball -> setVelocity(0, 500*GetFrameTime());
        addEntity(cannonball);
    }
}

