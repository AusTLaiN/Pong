#ifndef IBOTSTRATEGY_H
#define IBOTSTRATEGY_H

#include "player.h"
#include "ball.h"

struct BotStrategyArgs
{
    BotStrategyArgs();
    BotStrategyArgs(Player *bot, Ball *ball, double timePassed);

    Player *bot = nullptr;
    Ball *ball = nullptr;
    double timePassed = 0.0;
};

class IBotStrategy
{
public:
    IBotStrategy();
    virtual ~IBotStrategy();

    virtual void useStrategy(const BotStrategyArgs &args) const = 0;

protected:
    bool ballMovesToPlayer(Player *p, Ball *ball) const;
    bool ballOnPlayerSide(Player *p, Ball *ball) const;
};

#endif // IBOTSTRATEGY_H
