#pragma once
#include "entity.hpp"
class PhysicsEntity : public Entity {
    public:
        PhysicsEntity();
        void update() override;
        void draw() override;
        void setVelocity(float speedX, float speedY);
        Vector2 getVelocity();
        void setColliderSize(float width, float height);
        Vector2 getColliderSize();
        bool checkCollision(PhysicsEntity* otherEntity);
        virtual void onCollision(PhysicsEntity* otherEntity);
        void setColliderOffset(float offsetX, float offsetY);
        Vector2 getColliderOffset();
    private:
        Vector2 velocity = {0, 0};
        Vector2 colliderSize = {0, 0};
        Vector2 colliderOffset = {0, 0};
};