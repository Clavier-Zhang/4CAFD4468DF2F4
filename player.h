#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "abstractLevel.h"
#include <memory>
#include <vector>
#include <iostream>
#include "point.h"
#include "abstractBlock.h"
#include "window.h"
class Player {
    private:
        // level on the top left
        std::unique_ptr<AbstractLevel> level;
        // score on the top left
        int score = 0;
        // current on the top middle
        std::unique_ptr<AbstractBlock> currentBlock;
        // next block on the bottom middle
        std::unique_ptr<AbstractBlock> nextBlock;
        // grid on the bottom
        std::vector<std::vector<Point>> grid;
        // window
        Xwindow* xw;
    public:
        // initialzie the player, draw in the constructor, save window pointer
        Player();
        // player's operation
        // check if it is possible to level up/down
        void levelUp();
        void leveldown();
        // check if it's movable, then call block's method to move
        void moveLeft();
        void moveRight();
        void moveDown();
        void rotateClockwise();
        void rotateCounterClockwise();
        // add the points of blocks to grid, update the block in drop(), 
        void drop();
        // more commands
};
std::ostream& operator<<(std::ostream &out, const Player &p);
#endif