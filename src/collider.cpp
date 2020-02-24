#include "collider.h"

#include <cmath>

#include <iostream>
using namespace std;

ostream & operator << (ostream &out, Collider::CollisionSide side)
{
    string sideStr;

    if (side & Collider::CollisionSide::Top) {
        sideStr+= "Top";
    }

    if (side & Collider::CollisionSide::Bottom) {
        sideStr+= "Bottom";
    }

    if (side & Collider::CollisionSide::Left) {
        sideStr+= "Left";
    }

    if (side & Collider::CollisionSide::Right) {
        sideStr+= "Right";
    }

    out << sideStr;

    return out;
}


Collider::Collider()
{

}

std::vector<Entity *> Collider::collisionWithObjects(Entity *e, const std::vector<Entity *> &objects) const
{
    std::vector<Entity *> collided;
    Point2F pos = e->pos();
    Size size = e->size();

    for (auto obj : objects) {
        if (e == obj) {
            continue;
        }

        Point2F leftTop1(pos.x, pos.y);
        Point2F rightBottom1(pos.x + size.width, pos.y + size.height);
        Point2F leftTop2(obj->pos().x, obj->pos().y);
        Point2F rightBottom2(obj->pos().x + obj->size().width, obj->pos().y + obj->size().height);

        if ((leftTop1.x < rightBottom2.x) && (rightBottom1.x > leftTop2.x) &&
                (leftTop1.y < rightBottom2.y) && (rightBottom1.y > leftTop2.y)) {
            collided.push_back(obj);

            //cout << "Collision with object " << *obj << " || Collision side : " << getCollisonSide(e, obj) << endl;
        }
    }

    return collided;
}

bool Collider::collision(Entity *first, Entity *second) const
{
    return !collisionWithObjects(first, {second}).empty();
}

// computes distance from each side of object @first to @second
// returns closest one

Collider::CollisionSide Collider::getCollisonSide(Entity *first, Entity *second) const
{
    int side = CollisionSide::NoCollision;

    float distToLeft = fabs(first->pos().x - (second->pos().x + second->size().width));
    float distToRight = fabs(first->pos().x + first->size().width - second->pos().x);

    float distToTop = fabs(first->pos().y - (second->pos().y + second->size().height));
    float distToBottom = fabs(first->pos().y + first->size().height - second->pos().y);

    static const float precision = 1.0f;

    if (distToLeft < precision) {
        side |= CollisionSide::Left;
    } else if (distToRight < precision) {
        side |= CollisionSide::Right;
    }

    if (distToTop < precision) {
        side |= CollisionSide::Top;
    } else if (distToBottom < precision) {
        side |= CollisionSide::Bottom;
    }

    return static_cast<CollisionSide>(side);
}
