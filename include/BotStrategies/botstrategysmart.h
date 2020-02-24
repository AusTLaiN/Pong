#ifndef BOTSTRATEGYSMART_H
#define BOTSTRATEGYSMART_H

#include "botstrategycomputecenter.h"

class BotStrategySmart : public BotStrategyComputeCenter
{
public:
    BotStrategySmart();
    virtual ~BotStrategySmart();

    // IBotStrategy interface
public:
    virtual void useStrategy(Player *bot, Ball *ball, double timePassed) override;
};

#endif // BOTSTRATEGYSMART_H
