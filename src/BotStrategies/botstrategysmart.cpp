#include "botstrategysmart.h"

#include "gameinfo.h"

#include <cmath>
#include <iostream>
#include <memory>

BotStrategySmart::BotStrategySmart()
{

}

BotStrategySmart::~BotStrategySmart()
{

}

// improved ComputeCenter strategy
// if ball is moving away we move closer to the center

void BotStrategySmart::useStrategy(const BotStrategyArgs &args) const
{
    Ball *ball = args.ball;
    Player *bot = args.bot;

    if (ballMovesToPlayer(bot, ball) && ballOnPlayerSide(bot, ball)) {
        BotStrategyComputeCenter::useStrategy({bot, ball, args.timePassed});
    } else {
        // create dummy ball as target for movement
        static std::unique_ptr<Ball> dummy(new Ball(Point2F(GameInfo::gameWidth / 2.0f, GameInfo::gameHeight / 2.0f)));
        BotStrategyComputeCenter::useStrategy({bot, dummy.get(), args.timePassed});
    }
}
