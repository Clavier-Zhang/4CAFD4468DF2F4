#ifndef _ABSTRACTPLAYER_H_
#define _ABSTRACTPLAYER_H_
#include "abstractLevel.h"
#include <memory>
#include <vector>
#include <iostream>
#include "point.h"
#include "abstractBlock.h"
#include "window.h"
#include "game.h"
class AbstractPlayer {
    protected:
        // level on the top left
        std::unique_ptr<AbstractLevel> level;
        // score on the top left
        int currenntScore = 0;
        int highestScore = 0;
        // current on the top middle
        std::unique_ptr<AbstractBlock> currentBlock;
        // next block on the bottom middle
        std::unique_ptr<AbstractBlock> nextBlock;
        // grid on the bottom
        std::vector<std::vector<std::unique_ptr<Point>>> grid;
        // blocks already exists, will be checked and cleared
        std::vector<std::unique_ptr<AbstractBlock>> fieldBlocks;
        // window
        Xwindow *xw;
        // game for observer
        Game *game;
    public:
        // player's operation
        // check if it is possible to level up/down
        virtual void setLevel(int level) = 0;
        // check if it's movable, then call block's method to move
        virtual void moveLeft(int step = 1) = 0;
        virtual void moveRight(int step = 1) = 0;
        virtual void moveDown(int step = 1) = 0;
        virtual void rotateClockwise() = 0;
        virtual void rotateCounterClockwise() = 0;
        // add the points of blocks to grid, update the block in drop(), 
        virtual void drop() = 0;
        // more commands
        int getCurrentScore();
        int getHighestScore();
        std::vector<std::vector<Point>>* getGrid();
        AbstractLevel* getLevel();
        // assign the point pointer to currentBlock, can
        // be used in moveLeft, moveRight
        // target::block
        virtual void putPoint(int x, int y) = 0;
        virtual void removePoint(int x, int y) = 0;
        virtual void setRandom();
        // display
        virtual void setCurrentBlock() = 0;
        virtual std::string printLine() = 0;
        // notify
        void notifyGameover();
        void notifyTurnover();
        void notifySpecialAction();
        
};
std::ostream& operator<<(std::ostream &out, const AbstractPlayer &p) = 0;
#endif