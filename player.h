#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "abstractLevel.h"
#include <memory>
#include <vector>
#include <iostream>
#include "point.h"
#include "abstractBlock.h"
#include "window.h"
#include "game.h"
#include "abstractPlayer.h"
class Player : public AbstractPlayer {
    public:
        // initialzie the player, draw in the constructor, save window pointer
        Player();
        // player's operation
        // check if it is possible to level up/down
        void setLevel(int level) override;
        // check if it's movable, then call block's method to move
        void moveLeft(int step = 1) override;
        void moveRight(int step = 1) override;
        void moveDown(int step = 1) override;
        void rotateClockwise() override;
        void rotateCounterClockwise() override;
        // add the points of blocks to grid, update the block in drop(), 
        void drop() override;
        // more commands
        int getCurrentScore() override;
        int getHighestScore() override;
        std::vector<std::vector<Point>>* getGrid() override;
        AbstractLevel* getLevel() override;
        // assign the point pointer to currentBlock, can
        // be used in moveLeft, moveRight
        // target::block
        void putPoint(int x, int y) override;
        void removePoint(int x, int y) override;
        // display
        std::string printLine() override;
};
#endif