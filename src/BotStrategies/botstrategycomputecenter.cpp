#include "botstrategycomputecenter.h"

#include <iostream>

BotStrategyComputeCenter::BotStrategyComputeCenter()
{
    //std::cout << "BotStrategyComputeCenter::BotStrategyComputeCenter" << std::endl;
}

BotStrategyComputeCenter::~BotStrategyComputeCenter()
{
    //std::cout << "BotStrategyComputeCenter::~BotStrategyComputeCenter" << std::endl;
}

void BotStrategyComputeCenter::useStrategy(const BotStrategyArgs &args) const
{
    auto ball = args.ball;
    auto bot = args.bot;

    Point2F botPos = bot->pos();
    Point2F botCenter = bot->getCenter();
    Point2F ballCenter = ball->getCenter();
    double velocity = bot->velocity() * args.timePassed;

    if (botCenter.y > ballCenter.y) {
        botPos.y -= velocity;
    } else if (botCenter.y + bot->size().height / 2 < ballCenter.y) {
        botPos.y += velocity;
    }

    bot->setPos(botPos);
    bot->validatePosition();
}
