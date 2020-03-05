#ifndef BOTSTRATEGYSIMPLE_H
#define BOTSTRATEGYSIMPLE_H

#include "ibotstrategy.h"

class BotStrategySimple : public IBotStrategy
{
public:
    BotStrategySimple();
    virtual ~BotStrategySimple() override;

    // IBotStrategy interface
public:
    virtual void useStrategy(const BotStrategyArgs &args) const override;
};

#endif // BOTSTRATEGYSIMPLE_H
