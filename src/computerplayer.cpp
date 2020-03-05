#include "computerplayer.h"

#include "gameinfo.h"

#include <iostream>

ComputerPlayer::ComputerPlayer()
{
    m_isHuman = false;
    m_velocity = GameInfo::computerPlayerVelocity;

    //std::cout << "ComputerPlayer::ComputerPlayer" << std::endl;
}

ComputerPlayer::ComputerPlayer(const Point2F &pos) :
    ComputerPlayer()
{
    m_pos = pos;
}

ComputerPlayer::~ComputerPlayer()
{
    //std::cout << "ComputerPlayer::~ComputerPlayer" << std::endl;
}

void ComputerPlayer::useStrategy(const std::shared_ptr<Ball> &ball, double timePassed)
{
    if (m_strategy != nullptr) {
        m_strategy->useStrategy({shared_from_this(), ball, timePassed});
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
