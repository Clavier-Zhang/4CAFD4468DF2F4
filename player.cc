#include "player.h"
#include "abstractPlayer.h"
#include "game.h"
#include <memory>
#include "levelOne.h"
#include "levelTwo.h"
#include "coordinate.h"
#include "blockI.h"
#include <iostream>
using namespace std;

// initialzie the player, draw in the constructor, save window pointer
Player::Player(Game *game) : AbstractPlayer{game} {}
    
// player's operation
// check if it is possible to level up/down
void Player::setLevel(int level){
    if (level == 1) {
        this->level.reset(new LevelOne());
    } else if (level == 2) {
        this->level.reset(new LevelTwo());
    }
}

bool Player::move(std::string type, int step) {
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
    vector<pair<int, int>> coordinates;
    for (Point *p : currentBlock->getPoints()) {
        pair<int, int> c = make_pair(p->getX() + deltaX, p->getY() + deltaY);
        if (isValid(c)) {
            coordinates.emplace_back(c);
        } else {
            return false;
        }
    }
    // clear block first, then add points
    currentBlock->removeAllPoint();
    currentBlock->addPoints(coordinates, this);
    return true;
}

void Player::rotate(bool counter, int step) {
    // rotation matrix
    if (step % 4 == 0) return;

    vector<vector<int>> clockWise{{0,-1},{1,0}};
    vector<vector<int>> counterClockWise{{0,1},{-1,0}};
    vector<vector<int>>& current = clockWise;
    if (counter) {
        current = counterClockWise;
    }
    int numRotations = step % 4; // since 4 possible orientations
    // check if it's rotatable
    vector<pair<int, int>> coordinates;
 
    const pair<int, int> lowerLeft = currentBlock->getLowerLeft();
    pair<int, int> rotatedll = lowerLeft; // copy of the lowerLeft; same if not rotated
    
    for (int i = 0; i < numRotations; ++i) {
    rotatedll = make_pair(rotatedll.first * current[0][0] + rotatedll.second * current[1][0], rotatedll.first * current[0][1] + rotatedll.second * current[1][1]);
    }

    int deltaX = rotatedll.first - lowerLeft.first;
    int deltaY = rotatedll.second - lowerLeft.second;
    for (Point *p : currentBlock->getPoints()) {
        int x = p->getX();
        int y = p->getY();
        int rotateX = x;
        int rotateY = y;
        for (int i = 0; i < numRotations; ++i) {
        int newX = (rotateX * current[0][0] + rotateY * current[1][0]);
        int newY = (rotateX * current[0][1] + rotateY * current[1][1]);
        rotateX = newX;
        rotateY = newY;
        }
        rotateX -= deltaX;
        rotateY -= deltaY;
        pair<int, int> c = make_pair(rotateX, rotateY);
        if (isValid(c)) {
            coordinates.emplace_back(c);
        } else {
            return;
        }
    }
    // clear block first, then add points
    currentBlock->removeAllPoint();
    currentBlock->addPoints(coordinates, this);

}

// add the points of blocks to grid, update the block in drop(), 
void Player::drop(){
    while (move("down", 1)) {}
    fieldBlocks.emplace_back(shared_ptr<AbstractBlock>(currentBlock));
    currentBlock = nextBlock;
    currentBlock->initialize(this);
    nextBlock = level->generateBlock();
    recalculateGrid();
    notifyTurnover();
}

// assign the point pointer to currentBlock, can
// be used in moveLeft, moveRight
// target::block
void Player::setCurrentBlock() {}
void Player::setRandom() {} 
