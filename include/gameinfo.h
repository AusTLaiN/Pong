#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <string>
#include <vector>

class GameInfo
{
private:
    GameInfo();

public:
    enum class GameMode {
        Undefined = 0,

        PlayerVersusPlayer,
        PlayerVersusComputer,
        ComputerVersusComputer
    };

    enum class BotStrategy {
        Undefined = 0,

        Simple,
        ComputeCenter,
        Smart,
        ComputeLinesIntersection
    };

    static GameInfo & getInstance();

    static const char *fontPath;
    static const int fontSize = 20;

    static const int gameWidth = 1000;
    static const int gameHeight = 800;

    static const float ballStartPositionX;
    static const float ballStartPositionY;
    static const int ballRadius;
    static const double ballVelocity;
    static const double ballAcceleration;

    static const int playerWidth;
    static const int playerHeight;
    static const float player1StartPositionX;
    static const float player1StartPositionY;
    static const float player2StartPositionX;
    static const float player2StartPositionY;
    static const double playerVelocity;
    static const double computerPlayerVelocity;

    static const float roundPauseDurationSecs;

    GameInfo(GameInfo &) = delete;
    GameInfo& operator = (GameInfo &) = delete;

    std::vector<std::string> getGameModes() const;
    std::vector<std::string> getBotStrategies() const;

private:
    std::vector<std::string> m_gameModes;
    std::vector<std::string> m_botStrategies;
};

#endif // GAMEINFO_H
