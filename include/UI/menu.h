#ifndef MENU_H
#define MENU_H

#include "pong.h"
#include "button.h"

#include "SDL.h"
#include "SDL_ttf.h"

#include <vector>

class Menu : public Button
{
public:
    Menu();
    virtual ~Menu();

    int returnCode() const;
    int show();

    SDL_Renderer *renderer() const;
    void setRenderer(SDL_Renderer *renderer);

    TTF_Font *font() const;
    void setFont(TTF_Font *font);

    std::vector<Button> buttons() const;
    void setButtons(const std::vector<Button> &buttons);

private:
    void draw();

protected:
    int m_returnCode;
    std::vector<Button> m_buttons;
    SDL_Renderer *m_renderer = nullptr;
    TTF_Font *m_font = nullptr;
};

#endif // MENU_H
