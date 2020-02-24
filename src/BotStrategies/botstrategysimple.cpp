#include "botstrategysimple.h"

#include "computerplayer.h"

BotStrategySimple::BotStrategySimple()
{

}

BotStrategySimple::~BotStrategySimple()
{

}

void BotStrategySimple::useStrategy(Player *bot, Ball *ball, double timePassed)
{
    Point2F botPos = bot->pos();
    float velocity = bot->velocity() * timePassed;

    if (bot->pos().y > ball->pos().y) {
        botPos.y -= velocity;
    } else if (bot->pos().y + bot->size().height < ball->pos().y) {
        botPos.y += velocity;
    }

    bot->setPos(botPos);
    bot->validatePosition();
}
