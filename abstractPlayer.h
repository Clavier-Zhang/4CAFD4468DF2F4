#ifndef _ABSTRACTPLAYER_H_
#define _ABSTRACTPLAYER_H_
#include <memory>
#include <vector>
#include <iostream>
#include "point.h"
#include <string>
#include "abstractLevel.h"
#include <map>
#include "window.h"
#include "levelZero.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"
class AbstractBlock;
class Game;

class AbstractPlayer { 
    void updateScore();
    protected:
        // player number
        int no = 1;
        std::string initScpt; // if the player goes back to lvl 0 this is the used file name
        // level on the top left
        std::shared_ptr<AbstractLevel> level;
        // score on the top left
        int currentScore = 0;
        int highestScore = 0;
        const int rowNum = 18;
        const int reservedRowNum = 3;
        const int colNum = 11;
        std::unique_ptr<AbstractBlock>currentBlock;
        std::unique_ptr<AbstractBlock>nextBlock;

        bool isDecorated = false;
        int numDrop = 1;

        // grid on the bottom
        std::vector<std::vector<Point>> grid;
        // blocks already exists, will be checked and cleared
        std::map<int,std::unique_ptr<AbstractBlock>> inactiveBlocks;
        // game for observer
        Game *game;
        Xwindow *w;
    public:
        AbstractPlayer(Game *game, int no, Xwindow *w, std::string scpt);
        AbstractPlayer(Game *game);
        ~AbstractPlayer();
        // player's operation
        // check if it's movable, then call block's method to move
        virtual int move(std::string type, int step = 1, bool isBlind=false) = 0;
        virtual int rotate(bool counter = false, int step = 1, bool isBlind=false) = 0;
        // add the points of blocks to grid, update the block in drop(), 
        virtual void drop(bool shouldClear = false) = 0;
        // check if it is possible to level up/down
        void setLevel(int level);
        // assign the point pointer to currentBlock, can
        void setRandom(bool rand, std::string file = "");
        // display
        virtual void setCurrentBlock(char type = ' ') = 0;
        virtual std::shared_ptr<AbstractPlayer> getUnderlyingPlayer() = 0;
        virtual void nullifyUnderlyingPlayer() = 0;
        virtual void setUnderlyingPlayer(std::shared_ptr<AbstractPlayer>) = 0;

        void recalculateGrid();
        void recalculateInactiveBlocks();
        void clearRow(int row);
        //checks if you need to apply any special affects to player at the end of turn
        void applyLevelEffects(int);

        void shiftRowDown(int row, int offset);

        void setIsDecorated(bool);
        bool getIsDecorated();

        // observer pattern
        void notifyGameover();
        void notifyTurnover();
        void notifySpecialAction();
        // getter
        int getCurrentScore();
        int getHighestScore();
        int getLevel();
        int getNo();
        int getNumDrop();
        Game *getGame();
        std::string getInitScpt();
        virtual std::string getGridRow(int row) = 0;
        virtual std::string getGridPoint(int row, int col) = 0;
        virtual void drawGridPoint(int x, int y, int col) = 0;
        virtual void undrawGridPoint(int x, int y) = 0;
        std::string getNextBlock();
        void setNumDrop(int);
        void setNextBlock(std::string);
        void setCurrentBlock(std::string);
        void setHighScore(int );
        std::string getCurrentBlock();
        Point* getPoint(std::pair<int, int> &c);

        void setGridType(int row, int col, std::string c);

        // check if the point at c is valid
        bool isValid(std::pair<int, int> &c);
        // draw
        void drawScore();
        void undrawScore();
        void drawLevel();
        void undrawLevel();
        void drawNextBlock();
        void undrawNextBlock();
};
#endif
