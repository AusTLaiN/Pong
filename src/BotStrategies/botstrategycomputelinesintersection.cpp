#include "botstrategycomputelinesintersection.h"

#include "gameinfo.h"

#include <cmath>
#include <limits>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

namespace  {

class LinesIntersection
{
public:
    bool operator () (Point2F s1, Point2F e1, Point2F s2, Point2F e2)
    {
        float a1 = e1.y - s1.y;
        float b1 = s1.x - e1.x;
        float c1 = a1 * s1.x + b1 * s1.y;

        float a2 = e2.y - s2.y;
        float b2 = s2.x - e2.x;
        float c2 = a2 * s2.x + b2 * s2.y;

        float delta = a1 * b2 - a2 * b1;

        if (std::abs(delta - std::numeric_limits<float>::epsilon()) < 0) {
            m_intersect = false;
        } else {
            m_intersect = true;
            m_intersectionPoint = {(b2 * c1 - b1 * c2) / delta, (a1 * c2 - a2 * c1) / delta};
        }

        return m_intersect;
    }

    Point2F m_intersectionPoint;
    bool m_intersect = false;
};

}



BotStrategyComputeLinesIntersection::BotStrategyComputeLinesIntersection()
{

}

BotStrategyComputeLinesIntersection::~BotStrategyComputeLinesIntersection()
{

}

// Computes intersection of ball traectory with Player's side
// if ball traectory intersects with player side, bot moves to intersection point
// if ball traectory does not intersect player side, bot follows the ball
// if balls moves away, bot moves to center

void BotStrategyComputeLinesIntersection::useStrategy(const BotStrategyArgs &args) const
{
    auto ball = args.ball;
    auto bot = args.bot;

    // creating dummy ball as target for movement with it's base position on Player
    static auto dummy = std::make_shared<Ball>();

    if (ballMovesToPlayer(bot, ball)) {
        dummy->setPos(ball->pos());
        dummy->setAngle(ball->angle());
        dummy->move(20.0);

        Point2F p1 = ball->getCenter();
        Point2F p2 = dummy->getCenter();

        // Vertical line that goes through player center on X coordinate
        Point2F p3(bot->getCenter().x, 0);
        Point2F p4(bot->getCenter().x, 10);

        LinesIntersection i;
        if (i(p1, p2, p3, p4)) {
            if (i.m_intersectionPoint.y > 0 && i.m_intersectionPoint.y < GameInfo::gameHeight) {
                dummy->setPos(i.m_intersectionPoint);
                BotStrategyComputeCenter::useStrategy({bot, dummy, args.timePassed});
            } else if (ballOnPlayerSide(bot, ball)) {
                // follow the ball if it's traectory does not intersect player side
                dummy->setPos(ball->pos());
                BotStrategyComputeCenter::useStrategy({bot, dummy, args.timePassed});
            }

        }
    } else {
        // move to center if ball moves away
        dummy->setPos({0, GameInfo::gameHeight / 2.0f});
        BotStrategyComputeCenter::useStrategy({bot, dummy, args.timePassed});
    }
}
