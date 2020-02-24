#ifndef PONG_H
#define PONG_H

#include <ostream>

struct Point2F {
    Point2F() {}
    Point2F(float x, float y) : x(x), y(y) {}

    bool operator != (const Point2F &other);
    bool operator == (const Point2F &other);

    friend std::ostream & operator << (std::ostream &out, const Point2F &p);

    float x = 0;
    float y = 0;
};

struct Size {
    Size() {}
    Size(int width, int height) : width(width), height(height) {}

    bool operator != (const Size &other);
    bool operator == (const Size &other);

    friend std::ostream & operator << (std::ostream &out, const Size &s);

    int width = 0;
    int height = 0;
};

#endif // PONG_H
