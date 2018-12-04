#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <memory>
#include <vector>
#include <iostream>
#include "game.h"
#include "abstractPlayer.h"
#include "window.h"

class Player : public AbstractPlayer {
        // returns whether move/rotate was successful or not
        bool moveHelper(std::string type = "down", int step = 1, bool isBlind=false);
        bool rotateHelper(bool counter = false, int step = 1, bool isBlind=false);
        void clearBlind();
    public:
        // initialize the player, draw in the constructor, save window pointer
        Player(Game *game, int no, Xwindow *w, int startLevel,std::string scpt);
        // check if it's movable, then call block's method to move
        // int retval reflects how many steps it was able to complete
        // Transformation methods
        int move(std::string type = "down", int step = 1, bool isBlind=false) override;
        int rotate(bool counter = false, int step = 1, bool isBlind =false) override;
        void drop(bool) override;
        // display
        std::string getGridRow(int) override;
        std::string getGridPoint(int, int) override;
        void drawGridPoint(int x, int y, int col) override ;
        // Iterate through linked list of decorators
        std::shared_ptr<AbstractPlayer> getUnderlyingPlayer() override;
        void nullifyUnderlyingPlayer() override;
        void setUnderlyingPlayer(std::shared_ptr<AbstractPlayer>) override;
        // Override setters
        void setCurrentBlock(char) override;
        void setLevel(int) override;
        void setHighScore(int)override;
        void setNumDrop(int)override;
        void setRandom(bool rand, std::string file = "") override;
        // Override getters
        int getLevel() override;
        int getHighScore() override;
        int getNumDrop()override;
        int getCurrentScore()override;
};
#endif
