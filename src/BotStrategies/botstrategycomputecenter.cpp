#include "botstrategycomputecenter.h"

#include "computerplayer.h"

BotStrategyComputeCenter::BotStrategyComputeCenter()
{

}

BotStrategyComputeCenter::~BotStrategyComputeCenter()
{

}

void BotStrategyComputeCenter::useStrategy(Player *bot, Ball *ball, double timePassed)
{
    Point2F botPos = bot->pos();
    Point2F botCenter = bot->getCenter();
    Point2F ballCenter = ball->getCenter();
    float velocity = bot->velocity() * timePassed;

    if (botCenter.y > ballCenter.y) {
        botPos.y -= velocity;
    } else if (botCenter.y + bot->size().height / 2 < ballCenter.y) {
        botPos.y += velocity;
    }

    bot->setPos(botPos);
    bot->validatePosition();
}
