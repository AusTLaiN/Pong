#include "menu.h"

#include "gameinfo.h"

#include <iostream>
using namespace std;

Menu::Menu()
{

}

Menu::~Menu()
{

}

int Menu::returnCode() const
{
    return m_returnCode;
}

int Menu::show()
{
    SDL_Event e;

    while (true) {
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT ) {
                return 0;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN) {
                for (int i = 0; i < m_buttons.size(); ++i) {
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);

                    if (m_buttons[i].containsPoint(Point2F(mouseX, mouseY))) {
                        return m_returnCode = i + 1;
                    }
                }
            }
        }

        draw();
    }

    return 0;
}

void Menu::draw()
{
    // clear screen
    SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x0);
    SDL_RenderClear(m_renderer);

    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0x0);
    std::vector<SDL_Surface *> surfaces;
    std::vector<SDL_Texture *> textures;

    // menu header
    SDL_Surface* s = TTF_RenderText_Solid(m_font, m_text.c_str(), {0xFF, 0xFF, 0xFF, 0});
    SDL_Texture* t = SDL_CreateTextureFromSurface(m_renderer, s);
    SDL_Rect rect = {int(m_pos.x), int(m_pos.y), m_size.width, m_size.height};
    SDL_RenderCopy(m_renderer, t, nullptr, &rect);

    surfaces.push_back(s);
    textures.push_back(t);

    // buttons

    for (int i = 0; i < m_buttons.size(); ++i) {
        Button b = m_buttons[i];

        SDL_Color color = {0xFF, 0xFF, 0xFF, 0};
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        if (m_buttons[i].containsPoint(Point2F(mouseX, mouseY))) {
            color = {0x00, 0xFF, 0x00, 0};
        }

        SDL_Surface* s = TTF_RenderText_Solid(m_font, b.text().c_str(), color);
        SDL_Texture* t = SDL_CreateTextureFromSurface(m_renderer, s);
        SDL_Rect rect = {int(b.pos().x), int(b.pos().y), b.size().width, b.size().height};
        SDL_RenderCopy(m_renderer, t, nullptr, &rect);

        surfaces.push_back(s);
        textures.push_back(t);
    }

    // display
    SDL_RenderPresent(m_renderer);

    // delete[] makes no sense, SDL stuff created using malloc
    for (int i = 0; i < textures.size(); ++i) {
        SDL_DestroyTexture(textures[i]);
    }

    for (int i = 0; i < surfaces.size(); ++i) {
        SDL_FreeSurface(surfaces[i]);
    }
}

std::vector<Button> Menu::buttons() const
{
    return m_buttons;
}

void Menu::setButtons(const std::vector<Button> &buttons)
{
    m_buttons = buttons;
}

TTF_Font *Menu::font() const
{
    return m_font;
}

void Menu::setFont(TTF_Font *font)
{
    m_font = font;
}

SDL_Renderer *Menu::renderer() const
{
    return m_renderer;
}

void Menu::setRenderer(SDL_Renderer *renderer)
{
    m_renderer = renderer;
}
