#ifndef BALL_H
#define BALL_H

#include "entity.h"

class Ball : public Entity
{
public:
    Ball();
    Ball(double angle);
    Ball(const Point2F &pos, double angle = 0.0);
    virtual ~Ball();

    double angle() const;
    void setAngle(double angle);

    void move(double timePassed);

protected:
    double m_angle = 0.0;
};

#endif // BALL_H
