#pragma once
#include <raylib.h>
// This is a representation of any entity in the game world that have a visual representation (texture)
// and can move in the space
class Entity {
    public:
        Entity();
        virtual ~Entity();
        virtual void update();
        virtual void draw();
        void move(float x, float y);
        void setPosition(float x, float y);
        void setTexture(const char* path);
        void setHp(int hp);
        Vector2 getPosition();
        Texture2D getTexture();
        int getHp();
        void setActive(bool active);
        bool isActive();
        void destroy();
    private:
        Vector2 position;
        Texture2D texture;
        bool active = true;
        int hp;
};