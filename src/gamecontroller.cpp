#include "gamecontroller.h"

#include "SDL.h"

GameController::GameController()
{

}

void GameController::readInput(const Game &game, double timePassed) const
{
    auto player1 = game.getPlayers().front();
    auto player2 = game.getPlayers().back();

    auto move = [timePassed](Player *player, double v) {
        if (player == nullptr) {
            return;
        }

        Point2F pos = player->pos();
        pos.y += v * timePassed;
        player->setPos(pos);
        player->validatePosition();
    };


    const unsigned char *keys = SDL_GetKeyboardState(nullptr);

    // if Player2 is active UP DOWN is used by him
    // otherwise they are used by Player1 if he is human, and if he is not then target is set to null

    if (keys[SDL_SCANCODE_UP]) {
        auto target = player1->isHuman() ? player1 : nullptr;
        target = player2->isHuman() ? player2 : target;
        move(target, -target->velocity());
    }

    if (keys[SDL_SCANCODE_DOWN]) {
        auto target = player1->isHuman() ? player1 : nullptr;
        target = player2->isHuman() ? player2 : target;
        move(target, target->velocity());
    }

    if (keys[SDL_SCANCODE_W]) {
        if (player1->isHuman()) {
            move(player1, -player1->velocity());
        }
    }
    if (keys[SDL_SCANCODE_S]) {
        if (player1->isHuman()) {
            move(player1, player1->velocity());
        }
    }
}
