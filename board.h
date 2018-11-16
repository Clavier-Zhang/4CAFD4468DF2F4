#ifndef _BOARD_H_
#define _BOARD_H_
#include "player.h"
#include <memory>
#include <iostream>
#include "window.h"
class Board {
    private:
        // player one
        std::unique_ptr<Player> one;
        // player two
        std::unique_ptr<Player> two;
        // player in the current turn
        std::unique_ptr<Player> currentPlayer;
        // window, pass this pointer to subclasses
        std::unique_ptr<XWindow> xw;
    public:
        // initialize two players
        Board();
        // player's operation
        // do not need to check, call currentPlayer's method directly
        void levelUp();
        void leveldown();
        void moveLeft();
        void moveRight();
        void moveDown();
        void rotateClockwise();
        void rotateCounterClockwise();
        void drop();
        // more command to be determined
};
// text output
std::ostream& operator<<(std::ostream &out, const Board &b);
#endif