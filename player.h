#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <memory>
#include <vector>
#include <iostream>
#include "game.h"
#include "abstractPlayer.h"

class Player : public AbstractPlayer {
    public:
        // initialzie the player, draw in the constructor, save window pointer
        Player(Game *game);
        // player's operation
        // check if it is possible to level up/down
        void setLevel(int level) override;
        // check if it's movable, then call block's method to move
        bool move(std::string type = "down", int step = 1) override;
        void rotate(bool counter = false, int step = 1) override;
        // add the points of blocks to grid, update the block in drop(), 
        void drop() override;
        // assign the point pointer to currentBlock, can
        // be used in moveLeft, moveRight
        // target::block
        void setRandom() override;
        // display
        void setCurrentBlock() override; 
};
#endif
