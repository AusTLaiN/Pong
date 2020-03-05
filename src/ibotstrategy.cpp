#include "ibotstrategy.h"

#include "gameinfo.h"

#include <cmath>
#include <iostream>

BotStrategyArgs::BotStrategyArgs()
{

}

BotStrategyArgs::BotStrategyArgs(const std::shared_ptr<Player> &bot, const std::shared_ptr<Ball> &ball, double timePassed) :
    bot(bot),
    ball(ball),
    timePassed(timePassed)
{

}



IBotStrategy::IBotStrategy()
{
    //std::cout << "IBotStrategy::IBotStrategy" << std::endl;
}

IBotStrategy::~IBotStrategy()
{
    //std::cout << "IBotStrategy::~IBotStrategy" << std::endl;
}

bool IBotStrategy::ballMovesToPlayer(const std::shared_ptr<Player> &p, const std::shared_ptr<Ball> &ball) const
{
    if (p->pos().x > ball->pos().x && cos(ball->angle()) > 0) {
        return true;
    }

    if (p->pos().x < ball->pos().x && cos(ball->angle()) < 0) {
        return true;
    }

    return false;
}

bool IBotStrategy::ballOnPlayerSide(const std::shared_ptr<Player> &p, const std::shared_ptr<Ball> &ball) const
{
    return (fabs(p->pos().x - ball->pos().x) < GameInfo::gameWidth * 2 / 3);
}
