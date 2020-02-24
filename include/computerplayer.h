#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"
#include "ball.h"
#include "ibotstrategy.h"

class ComputerPlayer : public Player
{
public:
    ComputerPlayer();
    ComputerPlayer(const Point2F &pos);
    virtual ~ComputerPlayer();

    void useStrategy(Ball *ball, double timePassed);

    IBotStrategy *strategy() const;
    void setStrategy(IBotStrategy *strategy);

protected:
    IBotStrategy *m_strategy = nullptr;
};

#endif // COMPUTERPLAYER_H
