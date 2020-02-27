#include "ibotstrategy.h"

#include "gameinfo.h"

#include <cmath>

#include <iostream>
using namespace std;

BotStrategyArgs::BotStrategyArgs()
{

}

BotStrategyArgs::BotStrategyArgs(Player *bot, Ball *ball, double timePassed) :
    bot(bot),
    ball(ball),
    timePassed(timePassed)
{

}


IBotStrategy::IBotStrategy()
{
    //cout << "IBotStrategy::IBotStrategy" << endl;
}

IBotStrategy::~IBotStrategy()
{
    //cout << "IBotStrategy::~IBotStrategy" << endl;
}

bool IBotStrategy::ballMovesToPlayer(Player *p, Ball *ball) const
{
    if (p->pos().x > ball->pos().x && cos(ball->angle()) > 0) {
        return true;
    }

    if (p->pos().x < ball->pos().x && cos(ball->angle()) < 0) {
        return true;
    }

    return false;
}

bool IBotStrategy::ballOnPlayerSide(Player *p, Ball *ball) const
{
    return (fabs(p->pos().x - ball->pos().x) < GameInfo::gameWidth * 2 / 3);
}
