#include "ball.h"

#include "gameinfo.h"

#include <cmath>
#include <iostream>

Ball::Ball()
{
    m_pos.x = GameInfo::ballStartPositionX;
    m_pos.y = GameInfo::ballStartPositionY;
    m_size.width = m_size.height = GameInfo::ballRadius;
    m_velocity = GameInfo::ballVelocity;

    //std::cout << "Ball::Ball" << std::endl;
}

Ball::Ball(double angle) :
    Ball()
{
    m_angle = angle;
}

Ball::Ball(const Point2F &pos, double angle) :
    Ball()
{
    m_angle = angle;
    m_pos = pos;
}

Ball::~Ball()
{
    //std::cout << "Ball::~Ball" << std::endl;
}

double Ball::angle() const
{
    return m_angle;
}

void Ball::setAngle(double angle)
{
    m_angle = angle;
}

void Ball::move( double timePassed)
{
    m_pos.x = m_pos.x + m_velocity * cos(m_angle) * timePassed;
    m_pos.y = m_pos.y + m_velocity * sin(m_angle) * timePassed;
}
