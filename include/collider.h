#ifndef COLLIDER_H
#define COLLIDER_H

#include "entity.h"

#include <vector>

class Collider
{
public:
    enum CollisionSide {
        NoCollision = 0,

        Left = 1,
        Right = 2,
        Top = 4,
        Bottom = 8
    };

public:
    Collider();

    // checks for collision with other objects
    // returns list of objects that intersects with this one

    std::vector<Entity *> collisionWithObjects(Entity *e, const std::vector<Entity *> &objects) const;

    // returns true if this object intersects with another one

    bool collision(Entity *first, Entity *second) const;

    // returns intersection side

    CollisionSide getCollisonSide(Entity *first, Entity *second) const;
};

#endif // COLLIDER_H
