#include "ibotstrategy.h"

#include "gameinfo.h"

#include <cmath>

IBotStrategy::IBotStrategy()
{

}

IBotStrategy::~IBotStrategy()
{

}

bool IBotStrategy::ballMovesToPlayer(Player *p, Ball *ball)
{
    if (p->pos().x > ball->pos().x && cos(ball->angle()) > 0) {
        return true;
    }

    if (p->pos().x < ball->pos().x && cos(ball->angle()) < 0) {
        return true;
    }

    return false;
}

bool IBotStrategy::ballOnPlayerSide(Player *p, Ball *ball)
{
    return (fabs(p->pos().x - ball->pos().x) < GameInfo::gameWidth * 2 / 3);
}
