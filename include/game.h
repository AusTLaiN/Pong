#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

#include "player.h"
#include "ball.h"

class Game
{
public:
    Game(Player* player1, Player *player2, Ball *ball);
    ~Game();

    std::vector<Player *> getPlayers() const;

    Ball *ball() const;
    void setBall(Ball *ball);

    void update(double timePassed);
    bool roundFinished() const;
    void startNewRound();

private:
    void updateBall(double timePassed);

private:
    Player *m_player1 = nullptr;
    Player *m_player2 = nullptr;
    Ball *m_ball = nullptr;
    bool m_roundFinished = false;
};

#endif // GAMESTATE_H
