#include <raylib.h>
#include "ships.cpp"
#include <vector>



int main()
{
    // This sets the color of the background that simulate the sea
    Color backgroundColor = GetColor(0x36c5f400);

    const int screenWidth = 800;
    const int screenHeight = 600;


    InitWindow(screenWidth, screenHeight, "Fragata Down!");
    SetTargetFPS(60);

    int randomNum = GetRandomValue(1, 10);
    std::vector<Ship*> ships;
    for (int i = 0; i < randomNum; i++)
    {
        Ship *ship = new Ship();
        ship -> setPosition(GetRandomValue(0, screenWidth), GetRandomValue(0,screenHeight));
        ship -> setSpeed(0, GetRandomValue(-10,-20)*0.1);
        ships.push_back(ship);
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(backgroundColor);
        for (int i = 0; i < int(ships.size()); i++)
        {
            ships[i] -> update();
            ships[i] -> draw();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}