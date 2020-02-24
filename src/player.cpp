#include "player.h"

#include "gameinfo.h"

Player::Player()
{
    m_size.width = GameInfo::playerWidth;
    m_size.height = GameInfo::playerHeight;
    m_velocity = GameInfo::playerVelocity;
}

Player::Player(const Point2F &pos) :
    Entity (pos, {GameInfo::playerWidth, GameInfo::playerHeight})
{
    m_velocity = GameInfo::playerVelocity;
}

Player::~Player()
{

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
