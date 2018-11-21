#include "player.h"
#include "abstractPlayer.h"
#include "game.h"
#include "window.h"
#include <memory>
#include "levelOne.h"
#include "levelTwo.h"
#include "coordinate.h"
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

void Player::move(std::string type, int step) {
    int deltaX = 0;
    int deltaY = 0;
    if (type == "down") {
        deltaY = -step;
    }
    if (type == "left") {
        deltaX = -step;
    }
    if (type == "right") {
        deltaX = step;
    }
    vector<Coordinate> coordinates;
    // check if it's movable
    for (Point *p : this->currentBlock->getPoints()) {
        Coordinate c{p->getX() + deltaX, p->getY() + deltaY};
        if (this->isValid(c)) {
            coordinates.emplace_back(c);
        } else {
            return;
        }
    }
    this->currentBlock->removeAllPoint();
    this->currentBlock->addPoints(coordinates, this);
}

void Player::rotateClockwise(){}
void Player::rotateCounterClockwise(){}
// add the points of blocks to grid, update the block in drop(), 
void Player::drop(){}
// assign the point pointer to currentBlock, can
// be used in moveLeft, moveRight
// target::block
void Player::setCurrentBlock() {}
void Player::setRandom() {} 