#include "player.h"
#include "abstractPlayer.h"
#include "game.h"
#include "window.h"
#include <memory>
#include "levelOne.h"
#include "levelTwo.h"
#include <iostream>
using namespace std;

// initialzie the player, draw in the constructor, save window pointer
Player::Player(Game *game, Xwindow *xw) 
    : AbstractPlayer{game, xw} {}
    
// player's operation
// check if it is possible to level up/down
void Player::setLevel(int level){
    if (level == 1) {
        this->level.reset(new LevelOne());
    } else if (level == 2) {
        this->level.reset(new LevelTwo());
    }
}

// check if it's movable, then call block's method to move
void Player::moveLeft(int step){}
void Player::moveRight(int step){}
void Player::moveDown(int step){}
void Player::rotateClockwise(){}
void Player::rotateCounterClockwise(){}
// add the points of blocks to grid, update the block in drop(), 
void Player::drop(){}
// assign the point pointer to currentBlock, can
// be used in moveLeft, moveRight
// target::block
void Player::putPointToCurrentBlock(int x, int y){}
void Player::removePointFromCurrentBlock(int x, int y){}
void Player::setCurrentBlock() {}
void Player::setRandom() {} 