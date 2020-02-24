#include "gameinfo.h"

const char * GameInfo::fontPath = "resources/OpenSans-Regular.ttf";

const float GameInfo::ballStartPositionX = gameWidth / 2;
const float GameInfo::ballStartPositionY = gameHeight / 2;
const int GameInfo::ballRadius = 10;
const double GameInfo::ballVelocity = 300;
const double GameInfo::ballAcceleration = 30;

const int GameInfo::playerWidth = 10;
const int GameInfo::playerHeight = 50;
const float GameInfo::player1StartPositionX = 0;
const float GameInfo::player1StartPositionY = gameHeight / 2;
const float GameInfo::player2StartPositionX = gameWidth - playerWidth;
const float GameInfo::player2StartPositionY = gameHeight / 2;
const double GameInfo::playerVelocity = 600;
const double GameInfo::computerPlayerVelocity = playerVelocity * 0.75;

const float GameInfo::roundPauseDurationSecs = 0.5f;

GameInfo::GameInfo()
{
    m_gameModes = { "Player versus Player", "Player versus Computer", "Computer versus Computer" };
    m_botStrategies = { "Simple", "Compute Center", "Smart" , "Compute Lines Intersection" };
}

GameInfo &GameInfo::getInstance()
{
    static GameInfo info;
    return info;
}

std::vector<std::string> GameInfo::getGameModes() const
{
    return m_gameModes;
}

std::vector<std::string> GameInfo::getBotStrategies() const
{
    return m_botStrategies;
}
