#include "physics_entity.hpp"
#include <string>

PhysicsEntity::PhysicsEntity(){}

void PhysicsEntity::update()
{
    move(velocity.x, velocity.y);
}

void PhysicsEntity::draw()
{
    Entity::draw();
}

void PhysicsEntity::setVelocity(float speedX, float speedY)
{
    velocity.x = speedX;
    velocity.y = speedY;
}

Vector2 PhysicsEntity::getVelocity()
{
    return Vector2();
}

void PhysicsEntity::setColliderSize(float width, float height)
{
    colliderSize.x = width;
    colliderSize.y = height;
}

Vector2 PhysicsEntity::getColliderSize()
{
    return colliderSize;
}

bool PhysicsEntity::checkCollision(PhysicsEntity *otherEntity)
{
    Vector2 pos = getPosition();
    Vector2 colSize = getColliderSize();
    Vector2 offset = getColliderOffset();
    Vector2 oPos = otherEntity->getPosition();
    Vector2 oColSize = otherEntity->getColliderSize();
    Vector2 otOffset = otherEntity->getColliderOffset();
    //std::string colliderSizeString = std::to_string(oPos.x) + ", " + std::to_string(oPos.y);
    //DrawText(colliderSizeString.c_str(), 10, 30, 20, WHITE);
    // Checks if both colliders overlaps
    bool isColliding = (pos.x + offset.x < (oPos.x + oColSize.x+ otOffset.x) &&
                        (pos.x + colSize.x + offset.x) > oPos.x + otOffset.x &&
                        pos.y + offset.y < (oPos.y + oColSize.y +otOffset.y) &&
                        (pos.y + colSize.y + offset.y) > oPos.y + otOffset.y);
    return isColliding;
}

void PhysicsEntity::onCollision(PhysicsEntity *otherEntity)
{
}

void PhysicsEntity::setColliderOffset(float offsetX, float offsetY)
{
    colliderOffset.x = offsetX;
    colliderOffset.y = offsetY;
}
Vector2 PhysicsEntity::getColliderOffset()
{
    return colliderOffset;
}
