#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
public:
    Player();
    Player(const Point2F &pos);
    virtual ~Player();

    int score() const;
    void setScore(int score);

    bool isHuman() const;

protected:
    int m_score = 0;
    bool m_isHuman = true;
};

#endif // PLAYER_H
