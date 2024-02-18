#include <raylib.h>
#include "mainscene.hpp"
#include "game_settings.hpp"
#include <string>
using namespace game_settings;

int main()
{
    InitWindow(screenWidth, screenHeight, gameTitle);
    SetTargetFPS(60);

    MainScene mainScene = MainScene();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        mainScene.update();
        mainScene.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}