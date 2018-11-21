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
    // interpret command
    int deltaX = 0;
    int deltaY = 0;
    if (type == "down") {
        deltaY = step;
    }
    if (type == "left") {
        deltaX = -step;
    }
    if (type == "right") {
        deltaX = step;
    }
    // check if it's movable
    vector<Coordinate> coordinates;
    for (Point *p : this->currentBlock->getPoints()) {
        Coordinate c{p->getX() + deltaX, p->getY() + deltaY};
        if (this->isValid(c)) {
            coordinates.emplace_back(c);
        } else {
            return;
        }
    }
    // clear block first, then add points
    this->currentBlock->removeAllPoint();
    this->currentBlock->addPoints(coordinates, this);
}


void Player::rotate(bool counter, int step) {
    // rotation matrix
    vector<vector<int>> clockWise{{0,-1},{1,0}};
    vector<vector<int>> counterClockWise{{0,1},{-1,0}};
    vector<vector<int>>& current = clockWise;
    if (counter) {
        current = counterClockWise;
    }
    // check if it's rotatable
    vector<Coordinate> coordinates;
    for (Point *p : this->currentBlock->getPoints()) {
        int x = p->getX();
        int y = p->getY();
        int newX;
        int newY;
        for (int i = 0; i < step; i++) {
            newX = x*current[0][0] + y*current[1][0];
            newY = x*current[0][1] + y*current[1][1];
        }
        cout << x << "  " << y << endl;
        cout << newX << "  " << newY << endl;
        Coordinate c{newX, newY};
        if (this->isValid(c)) {
            coordinates.emplace_back(c);
        } else {
            return;
        }
    }
    // clear block first, then add points
    this->currentBlock->removeAllPoint();
    this->currentBlock->addPoints(coordinates, this);

}

// add the points of blocks to grid, update the block in drop(), 
void Player::drop(){}
// assign the point pointer to currentBlock, can
// be used in moveLeft, moveRight
// target::block
void Player::setCurrentBlock() {}
void Player::setRandom() {} 