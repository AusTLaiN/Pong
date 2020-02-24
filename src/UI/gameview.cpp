#include "gameview.h"

#include "gameinfo.h"

#include <iostream>
#include <algorithm>
#include <string>
using std::cout;
using std::endl;

GameView::GameView()
{
}

GameView::~GameView()
{

}

void GameView::drawEntity(Entity *obj)
{
    if (obj == nullptr) {
        std::cout << "GameView::drawEntity fail : entity is null" << endl;
        return;
    }
    int x = static_cast<int>(obj->pos().x);
    int y = static_cast<int>(obj->pos().y);
    int width = obj->size().width;
    int height = obj->size().height;

    SDL_Rect fillRect = {x, y, width, height};
    SDL_RenderFillRect(m_renderer, &fillRect);
}

void GameView::drawLine(const Point2F &p1, const Point2F &p2)
{
    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(m_renderer, p1.x, p1.y, p2.x, p2.y);
}

void GameView::debugDrawBallTraectory(Ball *b)
{
    Point2F p1 = b->getCenter();
    Ball *dummy = new Ball;
    dummy->setVelocity(b->velocity());
    dummy->setAngle(b->angle());
    dummy->move(100.0);
    Point2F p2 = dummy->pos();
    delete dummy;

    drawLine(p1, p2);
}

TTF_Font *GameView::font() const
{
    return m_font;
}

void GameView::setFont(TTF_Font *font)
{
    m_font = font;
}

SDL_Renderer *GameView::renderer() const
{
    return m_renderer;
}

void GameView::setRenderer(SDL_Renderer *renderer)
{
    m_renderer = renderer;
}

void GameView::draw(const Game &game)
{
    // clear screen
    SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x0);
    SDL_RenderClear(m_renderer);

    // draw players
    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    auto players = game.getPlayers();
    for (auto player : players) {
        drawEntity(static_cast<Entity *>(player));
    }

    // draw players score
    static const int offsetX = 100;
    static const int offsetY = 20;
    int p1Score = game.getPlayers().front()->score();
    int p2Score = game.getPlayers().back()->score();
    SDL_Color white = {255, 255, 255, 0};
    Size scoreSize = {30, 60};

    // Player 1 score
    SDL_Surface* s1 = TTF_RenderText_Solid(m_font, std::to_string(p1Score).c_str(), white);
    SDL_Texture* t1 = SDL_CreateTextureFromSurface(m_renderer, s1);
    SDL_Rect r1 = {offsetX, offsetY, scoreSize.width, scoreSize.height};
    SDL_RenderCopy(m_renderer, t1, nullptr, &r1);

    // Player 2 score
    SDL_Surface* s2 = TTF_RenderText_Solid(m_font, std::to_string(p2Score).c_str(), white);
    SDL_Texture* t2 = SDL_CreateTextureFromSurface(m_renderer, s2);
    SDL_Rect r2 = {GameInfo::gameWidth - offsetX, offsetY, scoreSize.width, scoreSize.height};
    SDL_RenderCopy(m_renderer, t2, nullptr, &r2);

    // draw ball
    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0x1A, 0x3C, 0xFF);
    drawEntity(game.ball());

    // debug draw ball traectory
    // debugDrawBallTraectory(game.ball());

    // display
    SDL_RenderPresent(m_renderer);

    SDL_DestroyTexture(t1);
    SDL_FreeSurface(s1);
    SDL_DestroyTexture(t2);
    SDL_FreeSurface(s2);
}
