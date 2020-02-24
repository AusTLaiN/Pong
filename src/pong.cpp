#include "pong.h"

#include <limits>
#include <cmath>

bool Point2F::operator !=(const Point2F &other)
{
    if(fabs(x - other.x) < std::numeric_limits<float>::epsilon() &&
       fabs(y - other.y) < std::numeric_limits<float>::epsilon()) {
        return false;
    }

    return true;
}

bool Point2F::operator ==(const Point2F &other)
{
    return !(*this != other);
}

bool Size::operator !=(const Size &other)
{
    return width != other.width || height != other.height;
}

bool Size::operator ==(const Size &other)
{
    return !(*this != other);
}

// cout overload

std::ostream & operator << (std::ostream &out, const Point2F &p)
{
    out << "Point2F(" << p.x << "," << p.y << ")";
    return out;
}

std::ostream & operator << (std::ostream &out, const Size &s)
{
    out << "Size(" << s.width << "," << s.height << ")";
    return out;
}
