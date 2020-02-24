#include "game.h"

#include "gameinfo.h"
#include "computerplayer.h"
#include "collider.h"

#include <cmath>
#include <iostream>
#include <algorithm>
#include <memory>
#include <limits.h>

using std::cout;
using std::endl;

Game::Game(Player *player1, Player *player2, Ball *ball) :
    m_player1(player1),
    m_player2(player2),
    m_ball(ball)
{
}

Game::~Game()
{
    delete m_player1;
    delete m_player2;
    delete m_ball;
}

void Game::updateBall(double timePassed)
{
    Point2F oldPos = m_ball->pos();

    m_ball->move(timePassed);
    m_ball->setVelocity(m_ball->velocity() + GameInfo::ballAcceleration * timePassed);

    static const float boundSize = 1e6f;
    static std::unique_ptr<Entity> leftBound(new Entity(Point2F(-boundSize, 0), Size(int(boundSize), GameInfo::gameHeight)));
    static std::unique_ptr<Entity> rightBound(new Entity(Point2F(GameInfo::gameWidth, 0), Size(int(boundSize), GameInfo::gameHeight)));
    static std::unique_ptr<Entity> topBound(new Entity(Point2F(0, -boundSize), Size(GameInfo::gameWidth, int(boundSize))));
    static std::unique_ptr<Entity> bottomBound(new Entity(Point2F(0, GameInfo::gameHeight), Size(GameInfo::gameWidth, int(boundSize))));

    // Player1 on the left side
    // Player2 on the right side

    Collider c;

    auto v1 = c.collisionWithObjects(m_ball, {leftBound.get(), rightBound.get()});
    if (!v1.empty()) {
        if (c.collision(m_ball, leftBound.get())) {
            m_player2->setScore(m_player2->score() + 1);
        } else if (c.collision(m_ball, rightBound.get())) {
            m_player1->setScore(m_player1->score() + 1);
        }

        m_roundFinished = true;
    }

    double bounceForce = GameInfo::ballRadius / 2.0;
    double ballScatter = (std::rand() % 20 + 10) * M_PI / 180.0;

    auto v2 = c.collisionWithObjects(m_ball, {topBound.get(), bottomBound.get()});
    if (!v2.empty()) {
        int cosSign = cos(m_ball->angle()) >= 0 ? 1 : -1;
        m_ball->setAngle(M_PI * 2 - m_ball->angle() + ballScatter * cosSign);
        Point2F p(oldPos);
        p.y += bounceForce * sin(m_ball->angle());
        m_ball->setPos(p);
    }

    auto v3 = c.collisionWithObjects(m_ball, {m_player1, m_player2});
    if (!v3.empty()) {
       int sinSign = sin(m_ball->angle()) >= 0 ? 1 : -1;
       m_ball->setAngle(M_PI - m_ball->angle() + ballScatter * sinSign);
       Point2F p(oldPos);
       p.x += bounceForce * cos(m_ball->angle());
       m_ball->setPos(p);
    }

    m_ball->validatePosition();
}

void Game::startNewRound()
{
    m_ball->setPos({GameInfo::ballStartPositionX, GameInfo::ballStartPositionY});
    m_ball->setVelocity(GameInfo::ballVelocity);
    m_ball->setAngle(rand() % 2 * M_PI);

    m_player1->setPos({GameInfo::player1StartPositionX, GameInfo::player1StartPositionY});
    m_player2->setPos({GameInfo::player2StartPositionX, GameInfo::player2StartPositionY});

    m_roundFinished = false;
}

std::vector<Player *> Game::getPlayers() const
{
    return {m_player1, m_player2};
}

Ball *Game::ball() const
{
    return m_ball;
}

void Game::setBall(Ball *ball)
{
    m_ball = ball;
}

void Game::update(double timePassed)
{
    if (m_roundFinished) {
        return;
    }

    updateBall(timePassed);

    if (m_roundFinished) {
        return;
    }

    for (auto player : getPlayers()) {
        auto bot = dynamic_cast<ComputerPlayer *>(player);
        if (bot != nullptr) {
            bot->useStrategy(m_ball, timePassed);
        }
    }
}

bool Game::roundFinished() const
{
    return m_roundFinished;
}
