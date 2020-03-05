#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <memory>

#include "player.h"
#include "ball.h"

class Game
{
public:
    Game(const std::shared_ptr<Player> &p1, const std::shared_ptr<Player> &p2, const std::shared_ptr<Ball> &ball);
    ~Game();

    std::vector<std::shared_ptr<Player>> getPlayers() const;

    void update(double timePassed);
    bool roundFinished() const;
    void startNewRound();

    std::shared_ptr<Ball> getBall() const;
    void setBall(const std::shared_ptr<Ball> &ball);

private:
    void updateBall(double timePassed);

private:
    std::shared_ptr<Player> m_player1;
    std::shared_ptr<Player> m_player2;
    std::shared_ptr<Ball> m_ball;

    bool m_roundFinished = false;
};

#endif // GAMESTATE_H
