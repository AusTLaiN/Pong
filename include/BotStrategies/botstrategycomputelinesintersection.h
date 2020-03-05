#ifndef BOTSTRATEGYCOMPUTELINESINTERSECTION_H
#define BOTSTRATEGYCOMPUTELINESINTERSECTION_H

#include "botstrategycomputecenter.h"

class BotStrategyComputeLinesIntersection : public BotStrategyComputeCenter
{
public:
    BotStrategyComputeLinesIntersection();
    virtual ~BotStrategyComputeLinesIntersection() override;

    // IBotStrategy interface
public:
    virtual void useStrategy(const BotStrategyArgs &args) const override;
};

#endif // BOTSTRATEGYCOMPUTELINESINTERSECTION_H
