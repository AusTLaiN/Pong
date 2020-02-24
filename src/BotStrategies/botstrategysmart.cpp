#include "botstrategysmart.h"

#include "gameinfo.h"

#include <cmath>

BotStrategySmart::BotStrategySmart()
{

}

BotStrategySmart::~BotStrategySmart()
{

}

// improved ComputeCenter strategy
// if ball is moving away we move closer to the center

void BotStrategySmart::useStrategy(Player *bot, Ball *ball, double timePassed)
{
    if (ballMovesToPlayer(bot, ball) && ballOnPlayerSide(bot, ball)) {
        BotStrategyComputeCenter::useStrategy(bot, ball, timePassed);
    } else {
        // create dummy ball as target for movement on Player's base position
        Ball *dummy = new Ball;
        dummy->setPos({static_cast<float>(GameInfo::gameWidth / 2), static_cast<float>(GameInfo::gameHeight / 2)});
        BotStrategyComputeCenter::useStrategy(bot, dummy, timePassed);
        delete dummy;
    }
}
