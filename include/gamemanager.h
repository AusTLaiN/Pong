#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "game.h"
#include "menu.h"
#include "gameinfo.h"
#include "gamecontroller.h"
#include "gameview.h"

#include "SDL.h"
#include "SDL_ttf.h"

#include <memory>

class GameManager
{
public:
    GameManager();
    ~GameManager();

    int initMedia();
    void initGame();

    void createUi();
    int showUi();
    void startGame();

    GameInfo::GameMode gameMode() const;

private:
    Menu createMenu(const std::string &menuText, const std::vector<std::string> &options);

private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;
    TTF_Font *m_font = nullptr;

    Menu m_gameModeMenu;
    Menu m_botStrategyMenu;

    GameInfo::GameMode m_gameMode = GameInfo::GameMode::Undefined;
    GameInfo::BotStrategy m_botStrategy = GameInfo::BotStrategy::Undefined;

    std::unique_ptr<Game> m_game;
    std::unique_ptr<GameController> m_controller;
    std::unique_ptr<GameView> m_view;

};

#endif // GAMEMANAGER_H
