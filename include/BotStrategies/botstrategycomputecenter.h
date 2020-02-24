#ifndef BOTSTRATEGYCOMPUTECENTER_H
#define BOTSTRATEGYCOMPUTECENTER_H

#include "ibotstrategy.h"

class BotStrategyComputeCenter : public IBotStrategy
{
public:
    BotStrategyComputeCenter();
    virtual ~BotStrategyComputeCenter();

    // IBotStrategy interface
public:
    virtual void useStrategy(Player *bot, Ball *ball, double timePassed) override;
};

#endif // BOTSTRATEGYCOMPUTECENTER_H
