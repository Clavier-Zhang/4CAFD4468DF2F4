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
        // check if it's movable, then call block's method to move
        bool move(std::string type = "down", int step = 1) override;
        void rotate(bool counter = false, int step = 1) override;
        // add the points of blocks to grid, update the block in drop(), 
        void drop() override;
        // display
        void setCurrentBlock(char type = ' ') override; 
        std::string getGridRow(int) override;
        std::string getGridPoint(int, int) override;
        std::shared_ptr<AbstractPlayer> getUnderlyingPlayer() override;
        void nullifyUnderlyingPlayer() override;
};
#endif
