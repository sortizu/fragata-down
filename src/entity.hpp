#pragma once
#include <raylib.h>
class Entity {
    public:
        Entity();
        ~Entity();
        void update();
        void draw();
        void move(int x, int y);
        void setPosition(int x, int y);
        void setSpeed(int x, int y);
        void setTexture(const char* path);
        void setHp(int hp);
        Vector2 getPosition();
        Vector2 getSpeed();
        Texture2D getTexture();
        int getHp();
        void destroy();
    private:
        Vector2 position;
        Vector2 speed;
        Texture2D texture;
        int hp;
};