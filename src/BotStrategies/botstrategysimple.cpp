#include "botstrategysimple.h"

#include <iostream>
using namespace std;

BotStrategySimple::BotStrategySimple()
{
    //cout << "BotStrategySimple:BotStrategySimple" << endl;
}

BotStrategySimple::~BotStrategySimple()
{
    //cout << "BotStrategySimple::~BotStrategySimple" << endl;
}

void BotStrategySimple::useStrategy(const BotStrategyArgs &args) const
{
    Ball *ball = args.ball;
    Player *bot = args.bot;

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
