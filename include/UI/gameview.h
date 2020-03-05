#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "game.h"

#include "SDL.h"
#include "SDL_ttf.h"

#include <memory>

class GameView
{
public:
    GameView();
    ~GameView();

    void draw(const Game &game);

    SDL_Renderer *renderer() const;
    void setRenderer(SDL_Renderer *renderer);

    TTF_Font *font() const;
    void setFont(TTF_Font *font);

private:
    void drawEntity(const std::shared_ptr<Entity> &obj);
    void drawLine(const Point2F &p1, const Point2F &p2);
    void debugDrawBallTraectory(const std::shared_ptr<Ball> &b);

private:
    SDL_Renderer *m_renderer = nullptr;
    TTF_Font *m_font = nullptr;
};

#endif // GAMEVIEW_H
