#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <memory>
#include <vector>
#include <iostream>
#include "game.h"
#include "abstractPlayer.h"
#include "window.h"

class Player : public AbstractPlayer {
        bool moveHelper(std::string type = "down", int step = 1, bool isBlind=false);
        bool rotateHelper(bool counter = false, int step = 1, bool isBlind=false);
        void clearBlind();
    public:
        // initialzie the player, draw in the constructor, save window pointer
        Player(Game *game, int no, Xwindow *w, int startLevel,std::string scpt);
        // check if it's movable, then call block's method to move
        int move(std::string type = "down", int step = 1, bool isBlind=false) override;
        int rotate(bool counter = false, int step = 1, bool isBlind =false) override;
        // add the points of blocks to grid, update the block in drop(), 
        void drop(bool) override;
        // display
        std::string getGridRow(int) override;
        std::string getGridPoint(int, int) override;
        void setCurrentBlock(char) override;
        // check if it is possible to level up/down
        std::shared_ptr<AbstractPlayer> getUnderlyingPlayer() override;
        void nullifyUnderlyingPlayer() override;
        void setUnderlyingPlayer(std::shared_ptr<AbstractPlayer>) override;
        void drawGridPoint(int x, int y, int col) override ;
        void undrawGridPoint(int x, int y) override;
        void setLevel(int) override;
        int getLevel() override;
        int getHighScore() override;
        void setHighScore(int)override;
        int getNumDrop()override;
        void setNumDrop(int)override;

//        bool canMoveDown(int step); //used in heavy dec
};
#endif
