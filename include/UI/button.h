#ifndef BUTTON_H
#define BUTTON_H

#include "pong.h"

#include <string>

class Button
{   
public:
    Button();
    Button(const Point2F &pos, const Size &size);
    Button(const Point2F &pos, const Size &size, const std::string &text);
    virtual ~Button();

    bool containsPoint(const Point2F &point) const;

    Point2F pos() const;
    void setPos(const Point2F &pos);

    Size size() const;
    void setSize(const Size &size);

    std::string text() const;
    void setText(const std::string &text);

protected:
    Point2F m_pos;
    Size m_size;
    std::string m_text;
};

#endif // BUTTON_H
