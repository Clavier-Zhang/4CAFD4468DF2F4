#ifndef _ABSTRACTPLAYER_H_
#define _ABSTRACTPLAYER_H_
#include <memory>
#include <vector>
#include <iostream>
#include "point.h"
#include <string>
#include "abstractLevel.h"
#include <map>
class AbstractBlock;
class Game;

class AbstractPlayer { 
    protected:
        // level on the top left
        int currID=0;//TODO:fix this
        std::shared_ptr<AbstractLevel> level;
        // score on the top left
        int currenntScore = 0;
        int highestScore = 0;
        int rowNum = 18;
        int reservedRowNum = 3;
        int colNum = 11;
        std::unique_ptr<AbstractBlock>currentBlock;
        std::unique_ptr<AbstractBlock>nextBlock;
       //AbstractBlock *currentBlock;
       // AbstractBlock *nextBlock;
        // grid on the bottom
        std::vector<std::vector<Point>> grid;
        // blocks already exists, will be checked and cleared
        std::map<int,std::unique_ptr<AbstractBlock>> inactiveBlocks;
        // game for observer
        Game *game;
    public:
        AbstractPlayer(Game *game);
        ~AbstractPlayer();
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
        void recalculateInactiveBlocks();
        void clearRow(int row);

        void shiftRowDown(int row, int offset);

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
        Point* getPoint(std::pair<int, int> &c);
        // check if the point at c is valid
        bool isValid(std::pair<int, int> &c);
};
#endif
