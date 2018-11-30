#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <memory>
#include <vector>
#include <iostream>
#include "game.h"
#include "abstractPlayer.h"
#include "window.h"

class Player : public AbstractPlayer {
        bool moveHelper(std::string type = "down", int step = 1);
        bool rotateHelper(bool counter = false, int step = 1);

    public:
        // initialzie the player, draw in the constructor, save window pointer
        Player(Game *game, int no, Xwindow *w);
        // check if it's movable, then call block's method to move
        int move(std::string type = "down", int step = 1) override;
        int rotate(bool counter = false, int step = 1) override;
        // add the points of blocks to grid, update the block in drop(), 
        void drop() override;
        // display
        std::string getGridRow(int) override;
        std::string getGridPoint(int, int) override;
        void setCurrentBlock(char) override;
        std::shared_ptr<AbstractPlayer> getUnderlyingPlayer() override;
        void nullifyUnderlyingPlayer() override;
};
#endif
