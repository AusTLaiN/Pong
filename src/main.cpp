#include "gamemanager.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    GameManager manager;

    if (manager.initMedia() != 0) {
        cout << "GameManager::initMedia failed" << endl;
        return 1;
    }

    manager.createUi();
    int retCode = manager.showUi();
    if (retCode != 0) {
        return retCode;
    }

    manager.initGame();
    manager.startGame();

    return 0;
}
