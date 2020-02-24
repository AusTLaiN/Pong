#include "button.h"

Button::Button()
{

}

Button::Button(const Point2F &pos, const Size &size) :
    m_pos(pos),
    m_size(size)
{

}

Button::Button(const Point2F &pos, const Size &size, const std::string &text) :
    Button(pos, size)
{
    m_text = text;
}

Button::~Button()
{

}

bool Button::containsPoint(const Point2F &point) const
{
    return (point.x > m_pos.x && point.x < m_pos.x + m_size.width) &&
           (point.y > m_pos.y && point.y < m_pos.y + m_size.height);
}

Point2F Button::pos() const
{
    return m_pos;
}

void Button::setPos(const Point2F &pos)
{
    m_pos = pos;
}

Size Button::size() const
{
    return m_size;
}

void Button::setSize(const Size &size)
{
    m_size = size;
}

std::string Button::text() const
{
    return m_text;
}

void Button::setText(const std::string &text)
{
    m_text = text;
}
