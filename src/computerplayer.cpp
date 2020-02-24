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
    delete m_strategy;
}

void ComputerPlayer::useStrategy(Ball *ball, double timePassed)
{
    if (m_strategy != nullptr) {
        m_strategy->useStrategy(this, ball, timePassed);
    }
}

IBotStrategy *ComputerPlayer::strategy() const
{
    return m_strategy;
}

void ComputerPlayer::setStrategy(IBotStrategy *strategy)
{
    delete m_strategy;
    m_strategy = strategy;
}
