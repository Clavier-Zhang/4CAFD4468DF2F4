#ifndef _GAME_H_
#define _GAME_H_
#include "player.h"
#include <memory>
#include <iostream>
#include "window.h"
class Game {
    private:
        // player one
        std::unique_ptr<Player> one;
        // player two
        std::unique_ptr<Player> two;
        // player in the current turn
        std::unique_ptr<Player> currentPlayer;
        // window, pass this pointer to subclasses
        std::unique_ptr<Xwindow> xw;
        // status of game
        bool isOver = false;
        bool needSpecial = false;
    public:
        // initialize two players
        Game();
        // player's operation
        // do not need to check, call currentPlayer's method directly
        void setLevel();
        void moveLeft();
        void moveRight();
        void moveDown();
        void rotateClockwise();
        void rotateCounterClockwise();
        void drop();
        // more command to be determined
        void gameOver();
        void turnOver();
        void specialAction();
};
// text output
std::ostream& operator<<(std::ostream &out, const Game &g);
#endif