#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "game.h"
#include "menu.h"
#include "gameinfo.h"
#include "gamecontroller.h"
#include "gameview.h"

#include "SDL.h"
#include "SDL_ttf.h"

class GameManager
{
public:
    GameManager();
    ~GameManager();

    int initMedia();
    void initGame();

    SDL_Renderer *renderer() const;
    TTF_Font *font() const;

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

    Game *m_game = nullptr;
    GameController *m_controller = nullptr;
    GameView *m_view = nullptr;

};

#endif // GAMEMANAGER_H
