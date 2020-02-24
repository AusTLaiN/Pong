#include "entity.h"

#include "gameinfo.h"

Entity::Entity()
{

}

Entity::Entity(const Point2F &pos, const Size &size) :
    m_pos(pos),
    m_size(size)
{

}

Entity::~Entity()
{

}

Point2F Entity::pos() const
{
    return m_pos;
}

void Entity::setPos(const Point2F &pos)
{
    m_pos = pos;
}

Size Entity::size() const
{
    return m_size;
}

void Entity::setSize(const Size &size)
{
    m_size = size;
}

double Entity::velocity() const
{
    return m_velocity;
}

void Entity::setVelocity(double velocity)
{
    m_velocity = velocity;
}

void Entity::validatePosition()
{
    if (m_pos.x < 0) {
        m_pos.x = 0;
    } else if (m_pos.x + m_size.width > GameInfo::gameWidth) {
        m_pos.x = GameInfo::gameWidth - m_size.width;
    }

    if (m_pos.y < 0) {
        m_pos.y = 0;
    } else if (m_pos.y + m_size.height > GameInfo::gameHeight) {
        m_pos.y = GameInfo::gameHeight - m_size.height;
    }
}

Point2F Entity::getCenter() const
{
    Point2F center;
    center.x = m_pos.x + m_size.width / 2;
    center.y = m_pos.y + m_size.height / 2;
    return center;
}

//

std::ostream & operator << (std::ostream &out, const Entity &e)
{
    out << "Entity(" << &e << ") : "
        << "Pos(" << e.m_pos << ") "
        << "Size(" << e.m_size << ") "
        << "Velocity(" << e.m_velocity << ")";
    return out;
}
