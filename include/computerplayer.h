#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"
#include "ball.h"
#include "ibotstrategy.h"

#include <memory>

class ComputerPlayer : public Player
{
public:
    ComputerPlayer();
    ComputerPlayer(const Point2F &pos);
    virtual ~ComputerPlayer();

    void useStrategy(Ball *ball, double timePassed);

    std::shared_ptr<IBotStrategy> strategy() const;
    void setStrategy(const std::shared_ptr<IBotStrategy> &strategy);

protected:
    std::shared_ptr<IBotStrategy> m_strategy;
};

#endif // COMPUTERPLAYER_H
