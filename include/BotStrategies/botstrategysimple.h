#ifndef BOTSTRATEGYSIMPLE_H
#define BOTSTRATEGYSIMPLE_H

#include "ibotstrategy.h"

class BotStrategySimple : public IBotStrategy
{
public:
    BotStrategySimple();
    virtual ~BotStrategySimple();

    // IBotStrategy interface
public:
    virtual void useStrategy(Player *bot, Ball *ball, double timePassed) override;
};

#endif // BOTSTRATEGYSIMPLE_H
