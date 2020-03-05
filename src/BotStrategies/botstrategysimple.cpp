#include "botstrategysimple.h"

#include <iostream>

BotStrategySimple::BotStrategySimple()
{
    //std::cout << "BotStrategySimple:BotStrategySimple" << std::endl;
}

BotStrategySimple::~BotStrategySimple()
{
    //std::cout << "BotStrategySimple::~BotStrategySimple" << std::endl;
}

void BotStrategySimple::useStrategy(const BotStrategyArgs &args) const
{
    auto ball = args.ball;
    auto bot = args.bot;

    Point2F botPos = bot->pos();
    double velocity = bot->velocity() * args.timePassed;

    if (bot->pos().y > ball->pos().y) {
        botPos.y -= velocity;
    } else if (bot->pos().y + bot->size().height < ball->pos().y) {
        botPos.y += velocity;
    }

    bot->setPos(botPos);
    bot->validatePosition();
}
