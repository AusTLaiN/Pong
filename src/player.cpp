#include "player.h"

#include "gameinfo.h"

#include <iostream>

Player::Player()
{
    m_size.width = GameInfo::playerWidth;
    m_size.height = GameInfo::playerHeight;
    m_velocity = GameInfo::playerVelocity;

    //std::cout << "Player::Player" << std::endl;
}

Player::Player(const Point2F &pos) :
    Player()
{
    m_pos = pos;
}

Player::~Player()
{
    //std::cout << "Player::~Player" << std::endl;
}

int Player::score() const
{
    return m_score;
}

void Player::setScore(int score)
{
    m_score = score;
}

bool Player::isHuman() const
{
    return m_isHuman;
}
