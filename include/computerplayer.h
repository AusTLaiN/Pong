#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"
#include "ball.h"
#include "ibotstrategy.h"

#include <memory>

class ComputerPlayer : public Player, public std::enable_shared_from_this<ComputerPlayer>
{
public:
    ComputerPlayer();
    ComputerPlayer(const Point2F &pos);
    virtual ~ComputerPlayer() override;

    void useStrategy(const std::shared_ptr<Ball> &ball, double timePassed);

    std::shared_ptr<IBotStrategy> strategy() const;
    void setStrategy(const std::shared_ptr<IBotStrategy> &strategy);

protected:
    std::shared_ptr<IBotStrategy> m_strategy;
};

#endif // COMPUTERPLAYER_H
