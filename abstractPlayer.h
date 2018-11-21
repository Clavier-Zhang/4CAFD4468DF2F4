#ifndef _ABSTRACTPLAYER_H_
#define _ABSTRACTPLAYER_H_
#include <memory>
#include <vector>
#include <iostream>
#include "point.h"
#include <string>
#include "abstractLevel.h"
#include "coordinate.h"
class AbstractBlock;
class Game;

class AbstractPlayer { 
    protected:
        // level on the top left
        std::shared_ptr<AbstractLevel> level;
        // score on the top left
        int currenntScore = 0;
        int highestScore = 0;
        int rowNum = 18;
        int reservedRowNum = 3;
        int colNum = 11;
        AbstractBlock *currentBlock;
        AbstractBlock *nextBlock;
        // grid on the bottom
        std::vector<std::vector<Point>> grid;
        // blocks already exists, will be checked and cleared
        std::vector<std::shared_ptr<AbstractBlock>> fieldBlocks;
        // game for observer
        Game *game;
    public:
        AbstractPlayer(Game *game);
        // player's operation
        // check if it is possible to level up/down
        virtual void setLevel(int level) = 0;
        // check if it's movable, then call block's method to move
        virtual bool move(std::string type, int step = 1) = 0;
        virtual void rotate(bool counter = false, int step = 1) = 0;
        // add the points of blocks to grid, update the block in drop(), 
        virtual void drop() = 0;
        // assign the point pointer to currentBlock, can
        virtual void setRandom() = 0;
        // display
        virtual void setCurrentBlock() = 0;

        void recalculateGrid();
        void recalculateFieldBlocks();
        bool isFull(int row);
        void clearRow(int row);
        void moveOneHigherRowDown(int row);
        void moveAllHigherRowDown(int row);
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
        Point* getPoint(/*Coordinate*/ std::pair<int, int> &c);
        // check if the point at c is valid
        bool isValid(/*Coordinate*/std::pair<int, int> &c);
};
#endif
