#ifndef _ABSTRACTPLAYER_H_
#define _ABSTRACTPLAYER_H_
#include <memory>
#include <vector>
#include <iostream>
#include "point.h"
#include "window.h"
#include <string>
class AbstractLevel;
class AbstractBlock;
class Game;

class AbstractPlayer {
    protected:
        // level on the top left
        AbstractLevel* level;
        // score on the top left
        int currenntScore = 0;
        int highestScore = 0;
        AbstractBlock* currentBlock;
        AbstractBlock* nextBlock;
        // grid on the bottom
        std::vector<std::vector<Point*>> grid;
        // blocks already exists, will be checked and cleared
        std::vector<AbstractBlock*> fieldBlocks;
        // window
        Xwindow *xw;
        // game for observer
        class Game *game;
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
        // assign the point pointer to currentBlock, can
        // be used in moveLeft, moveRight
        // target::block
        virtual void putPoint(int x, int y) = 0;
        virtual void removePoint(int x, int y) = 0;
        virtual void setRandom() = 0;
        // display
        virtual void setCurrentBlock() = 0;
        virtual std::string printLine() = 0;
        // notify
        void notifyGameover();
        void notifyTurnover();
        void notifySpecialAction();

        int getCurrentScore();
        int getHighestScore();
        std::vector<std::vector<Point>>* getGrid();
        AbstractLevel* getLevel();
        
};
std::ostream& operator<<(std::ostream &out, const AbstractPlayer &p);
#endif
