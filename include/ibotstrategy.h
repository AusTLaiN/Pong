#ifndef IBOTSTRATEGY_H
#define IBOTSTRATEGY_H

#include "player.h"
#include "ball.h"

class IBotStrategy
{
public:
    IBotStrategy();
    virtual ~IBotStrategy();

    virtual void useStrategy(Player *bot, Ball *ball, double timePassed) = 0;

protected:
    bool ballMovesToPlayer(Player *p, Ball *ball);
    bool ballOnPlayerSide(Player *p, Ball *ball);
};

#endif // IBOTSTRATEGY_H
