#ifndef BOTSTRATEGYCOMPUTELINESINTERSECTION_H
#define BOTSTRATEGYCOMPUTELINESINTERSECTION_H

#include "botstrategycomputecenter.h"

class BotStrategyComputeLinesIntersection : public BotStrategyComputeCenter
{
public:
    BotStrategyComputeLinesIntersection();
    virtual ~BotStrategyComputeLinesIntersection();

    // IBotStrategy interface
public:
    virtual void useStrategy(Player *bot, Ball *ball, double timePassed) override;
};

#endif // BOTSTRATEGYCOMPUTELINESINTERSECTION_H
