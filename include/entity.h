#ifndef ENTITY_H
#define ENTITY_H

#include <ostream>

#include "pong.h"

// base class for all game objects

class Entity
{
public:
    Entity();
    Entity(const Point2F &pos, const Size &size);
    virtual ~Entity();

    Point2F pos() const;
    void setPos(const Point2F &pos);

    Size size() const;
    void setSize(const Size &size);

    double velocity() const;
    void setVelocity(double velocity);

    void validatePosition();
    Point2F getCenter() const;

    friend std::ostream & operator << (std::ostream &out, const Entity &e);

protected:
    Point2F m_pos;
    Size m_size;
    double m_velocity = 0.0;
};

#endif // ENTITY_H
