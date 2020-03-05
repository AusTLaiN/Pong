#include "botstrategysmart.h"

#include "gameinfo.h"

#include <cmath>
#include <iostream>
#include <memory>

BotStrategySmart::BotStrategySmart()
{
    //std::cout << "BotStrategySmart::BotStrategySmart" << std::endl;
}

BotStrategySmart::~BotStrategySmart()
{
    //std::cout << "BotStrategySmart::~BotStrategySmart" << std::endl;
}

// improved ComputeCenter strategy
// if ball is moving away we move closer to the center

void BotStrategySmart::useStrategy(const BotStrategyArgs &args) const
{
    auto ball = args.ball;
    auto bot = args.bot;

    if (ballMovesToPlayer(bot, ball) && ballOnPlayerSide(bot, ball)) {
        BotStrategyComputeCenter::useStrategy({bot, ball, args.timePassed});
    } else {
        // create dummy ball as target for movement
        static auto dummy = std::make_shared<Ball>(Point2F(GameInfo::gameWidth / 2.0f, GameInfo::gameHeight / 2.0f));
        BotStrategyComputeCenter::useStrategy({bot, dummy, args.timePassed});
    }
}
