#ifndef _ABSTRACTPLAYER_H_
#define _ABSTRACTPLAYER_H_
#include <memory>
#include <vector>
#include <iostream>
#include "point.h"
#include "window.h"
#include <string>
#include "abstractLevel.h"
class AbstractBlock;
class Game;

class AbstractPlayer { 
    protected:
        // level on the top left
        std::shared_ptr<AbstractLevel> level;
        // score on the top left
        int currenntScore = 0;
        int highestScore = 0;
        int rowNum = 15;
        int colNum = 11;
        std::shared_ptr<AbstractBlock> currentBlock;
        std::shared_ptr<AbstractBlock> nextBlock;
        // grid on the bottom
        std::vector<std::vector<Point>> grid;
        // blocks already exists, will be checked and cleared
        std::vector<AbstractBlock*> fieldBlocks;
        // window
        Xwindow *xw;
        // game for observer
        Game *game;
    public:
        // constructor
        AbstractPlayer(Game *game, Xwindow *xw);
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
        virtual void putPointToCurrentBlock(int x, int y) = 0;
        virtual void removePointFromCurrentBlock(int x, int y) = 0;
        virtual void setRandom() = 0;
        // display
        virtual void setCurrentBlock() = 0;

        // observer pattern
        void notifyGameover();
        void notifyTurnover();
        void notifySpecialAction();
        // getter
        int getCurrentScore();
        int getHighestScore();
        int getLevel();
        std::string getGridRow(int row);
        std::string getNextBlock();
        // helper later
        // replace the current with next block
        // and initialize it. and get new next block
        void updateCurrentBlock();
        
};
#endif
