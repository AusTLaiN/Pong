#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "game.h"

class GameController
{
public:
    GameController();

    void readInput(const Game &game, double timePassed) const;
};

#endif // GAMECONTROLLER_H
