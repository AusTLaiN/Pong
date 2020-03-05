#include "gamemanager.h"

#include "computerplayer.h"
#include "botstrategies.h"

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <memory>

using namespace std;
using namespace std::chrono;

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();

    TTF_CloseFont(m_font);
    TTF_Quit();
}

int GameManager::initMedia()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
          cout << "SDL_Init failed: " << SDL_GetError() << endl;
          return 1;
      }

    if(TTF_Init() != 0) {
        cout << "TTF_Init failed: " << TTF_GetError() << endl;
        return 2;
    }

    SDL_Window *window = SDL_CreateWindow("Hong-pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GameInfo::gameWidth, GameInfo::gameHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cout << "GameManager::initMedia: failed to create window" << endl;
          return 3;
    }

    m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    m_font = TTF_OpenFont(GameInfo::fontPath, GameInfo::fontSize);

    if (m_renderer == nullptr) {
        cout << "Failed to create SDL Renderer" << endl;
        return 4;
    }

    if (m_font == nullptr) {
        cout << "Failed to load Font" << endl;
        return 5;
    }

    return 0;
}

void GameManager::initGame()
{
    srand(time(nullptr));

    std::shared_ptr<Player> p1;
    std::shared_ptr<Player> p2;

    switch (m_gameMode) {
        case GameInfo::GameMode::PlayerVersusPlayer:
        p1 = std::make_shared<Player>();
        p2 = std::make_shared<Player>();
        break;
        case GameInfo::GameMode::PlayerVersusComputer:
        p1 = std::make_shared<Player>();
        p2 = std::make_shared<ComputerPlayer>();
        break;
        case GameInfo::GameMode::ComputerVersusComputer:
        p1 = std::make_shared<ComputerPlayer>();
        p2 = std::make_shared<ComputerPlayer>();
        break;

        default:
        break;
    }

    p1->setPos({GameInfo::player1StartPositionX, GameInfo::player1StartPositionY});
    p2->setPos({GameInfo::player2StartPositionX, GameInfo::player2StartPositionY});

    shared_ptr<IBotStrategy> botStrat;
    switch (m_botStrategy) {
        case GameInfo::BotStrategy::Simple:
        botStrat = make_shared<BotStrategySimple>();
        break;
        case GameInfo::BotStrategy::ComputeCenter:
        botStrat = make_shared<BotStrategyComputeCenter>();
        break;
        case GameInfo::BotStrategy::Smart:
        botStrat = make_shared<BotStrategySmart>();
        break;
        case GameInfo::BotStrategy::ComputeLinesIntersection:
        botStrat = make_shared<BotStrategyComputeLinesIntersection>();
        break;

        default:
        break;
    }

    for (auto p : {p1, p2}) {
        auto bot = dynamic_cast<ComputerPlayer *>(p.get());
        if (bot != nullptr) {
            bot->setStrategy(botStrat);
        }
    }

    m_game.reset(new Game(p1, p2, std::make_shared<Ball>()));
    m_controller.reset(new GameController);
    m_view.reset(new GameView);
    m_view->setRenderer(m_renderer);
    m_view->setFont(m_font);
}

void GameManager::startGame()
{
    high_resolution_clock::time_point gameStart = high_resolution_clock::now();
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2 = gameStart;
    high_resolution_clock::time_point lastRoundFinishedAt = gameStart;

    m_game->startNewRound();
    SDL_Event e;
    volatile bool quit = false;
    while (!quit) {
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT ) {
                quit = true;
            }
        }

        t1 = t2;
        t2 = high_resolution_clock::now();
        duration<double> timePassed = duration_cast<duration<double>>(t2 - t1);
        duration<double> timePassedFromLastRound = duration_cast<duration<double>>(high_resolution_clock::now() - lastRoundFinishedAt);

        if (lastRoundFinishedAt == gameStart || timePassedFromLastRound.count() >= GameInfo::roundPauseDurationSecs) {
            m_controller->readInput(*m_game, timePassed.count());
            m_game->update(timePassed.count());
            m_view->draw(*m_game);
        }

        if (m_game->roundFinished()) {
            lastRoundFinishedAt = high_resolution_clock::now();
            m_game->startNewRound();
        }
    }

    duration<double> time_span = duration_cast<duration<double>>(high_resolution_clock::now() - gameStart);
    cout << "Total game time : " << time_span.count() << endl;
}

int GameManager::showUi()
{
    m_gameMode = static_cast<GameInfo::GameMode>(m_gameModeMenu.show());
    if (m_gameMode == GameInfo::GameMode::Undefined) {
        return 1;
    }

    if (m_gameMode != GameInfo::GameMode::PlayerVersusPlayer) {
        m_botStrategy = static_cast<GameInfo::BotStrategy>(m_botStrategyMenu.show());
    }

    if (m_gameMode != GameInfo::GameMode::PlayerVersusPlayer && m_botStrategy == GameInfo::BotStrategy::Undefined) {
        return 2;
    }

    int gMode = static_cast<int>(m_gameMode);
    int botStrat = static_cast<int>(m_botStrategy);
    string gModeStr = "Undefined";
    string botStratStr = "Undefined";

    if (gMode > 0) {
        gModeStr = GameInfo::getInstance().getGameModes()[gMode - 1];
    }
    if (botStrat > 0) {
        botStratStr = GameInfo::getInstance().getBotStrategies()[botStrat - 1];
    }
    cout << "Game mode selected : " << gMode << " " << gModeStr << endl;
    cout << "Bot strategy selected : " << botStrat << " " << botStratStr << endl;

    return 0;
}

void GameManager::createUi()
{
    m_gameModeMenu = createMenu("Select game mode", GameInfo::getInstance().getGameModes());
    m_botStrategyMenu = createMenu("Select bot strategy", GameInfo::getInstance().getBotStrategies());
}


Menu GameManager::createMenu(const std::string &menuText, const std::vector<string> &options)
{
    Menu m;
    vector<Button> menuButtons;
    m.setText(menuText);

    auto textSize = [this] (const std::string &text) -> Size {
        int w, h;
        TTF_SizeText(m_font, text.c_str(), &w, &h);
        return Size(w, h);
    };

    m.setSize(textSize(menuText));

    for (size_t i = 0; i < options.size(); ++i) {
        Button b;
        Size size = textSize(options[i]);

        b.setSize(size);
        b.setText(options[i]);

        if (m.size().width < size.width) {
            m.setSize(Size(size.width, m.size().height));
        }

        menuButtons.push_back(b);
    }

    int buttonHeight = menuButtons.front().size().height;
    static const int buttonPadding = 20;
    float menuPosX = GameInfo::gameWidth / 2.f - m.size().width / 2.f;
    float menuPosY = (GameInfo::gameHeight - (buttonHeight + buttonPadding) * options.size()) / 2;
    m.setPos({menuPosX, buttonPadding * 5});

    for (size_t i = 0; i < menuButtons.size(); ++i) {
        int wDiff = (m.size().width - menuButtons[i].size().width) / 2;
        menuButtons[i].setPos({menuPosX + wDiff, menuPosY + (buttonHeight  + buttonPadding) * i});
    }

    m.setButtons(menuButtons);
    m.setRenderer(m_renderer);
    m.setFont(m_font);

    return m;
}

GameInfo::GameMode GameManager::gameMode() const
{
    return m_gameMode;
}
