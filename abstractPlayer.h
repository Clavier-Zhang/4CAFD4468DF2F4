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
        // Private helper functions
        void shiftRowDown(int row, int offset); // used in recalculateGrid
        bool isValid(std::pair<int, int> &c); // used as a helper in subclesses
        void recalculateGrid();
        void recalculateInactiveBlocks();
        void clearRow(int row);
        void applyLevelEffects(int); // checks if you need to apply special
                                     // effects to player at end of turn
        void setNextBlock(std::string); // for access by AbstractDecorator
    public:
        AbstractPlayer(Game *game, int no, Xwindow *w, std::string scpt);
        AbstractPlayer(Game *game);
        ~AbstractPlayer();
        // Pure virtual transformation methods
        virtual int move(std::string type, int step = 1, bool isBlind=false) = 0;
        virtual int rotate(bool counter = false, int step = 1, bool isBlind=false) = 0;
        virtual void drop(bool shouldClear = false) = 0; // add the points of block to grid, update the block in drop()
        // Pure virtual setters
        virtual void setLevel(int level) = 0; // check if posible to level up/down
        virtual void setRandom(bool rand, std::string file = "")=0;
        virtual void setCurrentBlock(char type = ' ') = 0; 
        // Iterate through decorators
        virtual std::shared_ptr<AbstractPlayer> getUnderlyingPlayer() = 0;
        virtual void nullifyUnderlyingPlayer() = 0;
        virtual void setUnderlyingPlayer(std::shared_ptr<AbstractPlayer>) = 0;

        // Observer pattern
        void notifyGameover();
        void notifyTurnover();
        void notifySpecialAction();
        // getters
        virtual int getCurrentScore() = 0;
        virtual int getHighScore() = 0;
        virtual int getLevel() = 0;
        int getNo();
        virtual int getNumDrop() = 0;
        std::string getInitScpt();
        virtual std::string getGridRow(int row) = 0;
        virtual std::string getGridPoint(int row, int col) = 0;
        virtual void drawGridPoint(int x, int y, int col) = 0;
        std::string getNextBlock();
        virtual void setNumDrop(int) = 0;
        void setCurrentBlock(std::string);
        virtual void setHighScore(int) = 0;
        std::string getCurrentBlock();
        Point* getPoint(std::pair<int, int> &c);

        void setGridType(int row, int col, std::string c);

        // draw
        void drawScore();
        void undrawScore();
        void drawLevel();
        void undrawLevel();
        void drawNextBlock();
        void undrawNextBlock();

        bool canMoveDown(int step); //used in heavy dec
};
#endif
