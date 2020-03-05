#ifndef COLLIDER_H
#define COLLIDER_H

#include "entity.h"

#include <vector>
#include <memory>

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

    std::vector<std::shared_ptr<Entity>> collisionWithObjects(const std::shared_ptr<Entity> &e, const std::vector<std::shared_ptr<Entity>> &objects) const;

    // returns true if this object intersects with another one

    bool collision(const std::shared_ptr<Entity> &first, const std::shared_ptr<Entity> &second) const;

    // returns intersection side

    CollisionSide getCollisonSide(const std::shared_ptr<Entity> &first, const std::shared_ptr<Entity> &second) const;
};

#endif // COLLIDER_H
