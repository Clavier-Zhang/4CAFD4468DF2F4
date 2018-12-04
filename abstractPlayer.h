#ifndef _ABSTRACTPLAYER_H_
#define _ABSTRACTPLAYER_H_
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "abstractLevel.h"
#include "point.h"
#include "window.h"
class AbstractBlock;
class Game;

class AbstractPlayer { 
    void updateScore();
    protected:
        const int ROW = 18;
        const int RESERVE_ROW = 3;
        const int COL = 11;
        
        int no = 1; // player number
        std::string initScpt; // if the player goes back to lvl 0 this is the used file name
        int numDrop = 1;//how many consecutive drops should the player make
    
        std::shared_ptr<AbstractLevel> level; // level of player
        int currentScore = 0; // the current score of the current round of teris
        int highestScore = 0; // the player's high score
        
        std::unique_ptr<AbstractBlock>currentBlock;
        std::unique_ptr<AbstractBlock>nextBlock;


        std::vector<std::vector<Point>> grid; // grid on the bottom
        std::map<int,std::unique_ptr<AbstractBlock>> inactiveBlocks; // blocks already exist
                                                                     // will be checked and cleared
        Game *game; // game for Observer
        Xwindow *w;

        // Protected helper functions
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
        virtual void drop(bool isBlind = false) = 0; // add the points of block to grid, update the block in drop()
        // Pure virtual setters
        virtual void setLevel(int level) = 0; // check if posible to level up/down
        virtual void setRandom(bool rand, std::string file = "")=0;
        virtual void setCurrentBlock(char type = ' ') = 0; 
        virtual void setNumDrop(int) = 0;
        virtual void setHighScore(int) = 0;
        // Pure virtual getters
        virtual int getCurrentScore() = 0;
        virtual int getHighScore() = 0;
        virtual int getLevel() = 0;
        virtual int getNumDrop() = 0;
        virtual std::string getGridRow(int row) = 0;
        virtual std::string getGridPoint(int row, int col) = 0;
        // Iterate through decorators
        virtual std::shared_ptr<AbstractPlayer> getUnderlyingPlayer() = 0;
        virtual void nullifyUnderlyingPlayer() = 0;
        virtual void setUnderlyingPlayer(std::shared_ptr<AbstractPlayer>) = 0;
        //helper function for decorator
        bool canMoveDown(int step);
        // Observer pattern
        void notifyGameover();
        void notifyTurnover();
        void notifySpecialAction();
        // Regular getters
        int getNo();
        std::string getInitScpt();
        std::string getNextBlock();
        std::string getCurrentBlock();
        Point* getPoint(std::pair<int, int> &c);
        // Regular setter
        void setGridType(int row, int col, std::string c);
       
       // draw
        void drawScore();
        void undrawScore();
        void drawLevel();
        void undrawLevel();
        void drawNextBlock();
        void undrawNextBlock();
        virtual void drawGridPoint(int x, int y, int col) = 0;

};
#endif
