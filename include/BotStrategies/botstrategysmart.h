#ifndef BOTSTRATEGYSMART_H
#define BOTSTRATEGYSMART_H

#include "botstrategycomputecenter.h"

class BotStrategySmart : public BotStrategyComputeCenter
{
public:
    BotStrategySmart();
    virtual ~BotStrategySmart() override;

    // IBotStrategy interface
public:
    virtual void useStrategy(const BotStrategyArgs &args) const override;
};

#endif // BOTSTRATEGYSMART_H
