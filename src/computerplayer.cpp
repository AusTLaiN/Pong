#include "computerplayer.h"

#include "gameinfo.h"

ComputerPlayer::ComputerPlayer()
{
    m_isHuman = false;
    m_velocity = GameInfo::computerPlayerVelocity;
}

ComputerPlayer::ComputerPlayer(const Point2F &pos) :
    ComputerPlayer()
{
    m_pos = pos;
}

ComputerPlayer::~ComputerPlayer()
{
}

void ComputerPlayer::useStrategy(Ball *ball, double timePassed)
{
    if (m_strategy != nullptr) {
        m_strategy->useStrategy({this, ball, timePassed});
    }
}

std::shared_ptr<IBotStrategy> ComputerPlayer::strategy() const
{
    return m_strategy;
}

void ComputerPlayer::setStrategy(const std::shared_ptr<IBotStrategy> &strategy)
{
    m_strategy = strategy;
}
