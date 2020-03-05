#ifndef IBOTSTRATEGY_H
#define IBOTSTRATEGY_H

#include "player.h"
#include "ball.h"

#include <memory>

struct BotStrategyArgs
{
    BotStrategyArgs();
    BotStrategyArgs(const std::shared_ptr<Player> &bot, const std::shared_ptr<Ball> &ball, double timePassed);

    std::shared_ptr<Player> bot;
    std::shared_ptr<Ball> ball;
    double timePassed = 0.0;
};

class IBotStrategy
{
public:
    IBotStrategy();
    virtual ~IBotStrategy();

    virtual void useStrategy(const BotStrategyArgs &args) const = 0;

protected:
    bool ballMovesToPlayer(const std::shared_ptr<Player> &p, const std::shared_ptr<Ball> &ball) const;
    bool ballOnPlayerSide(const std::shared_ptr<Player> &p, const std::shared_ptr<Ball> &ball) const;
};

#endif // IBOTSTRATEGY_H
