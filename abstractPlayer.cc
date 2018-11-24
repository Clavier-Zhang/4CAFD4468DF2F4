#include "abstractPlayer.h"
#include "game.h"
#include "abstractLevel.h"
#include "levelZero.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"
#include "point.h"
#include <string.h>
#include <memory>
#include <map>
#include <iostream>
using namespace std;

// constructor
AbstractPlayer::AbstractPlayer(Game *game) {
    // initialize the grid
    for (int i = 0; i < rowNum; i++) {
        vector<Point> row;
        for (int j = 0; j < colNum; j++) {
            string empty = " ";
            row.emplace_back(Point(j,i,empty));
        }
        grid.emplace_back(row);
    }
    level = shared_ptr<AbstractLevel>(new LevelZero());
    currentBlock = this->level->generateBlock();
    nextBlock = this->level->generateBlock();
    currentBlock->initialize(this);
    this->game = game;
}

bool AbstractPlayer::isValid(pair<int, int> &c) {
    if (c.first < 0 || c.second < 0) {
        return false;
    }
    if (c.first >= colNum || c.second >= rowNum) {
        return false;
    }
    Point *p = this->getPoint(c);
    if (p->getType() != " " && !currentBlock->contain(p)) {
        return false;
    }
    return true;
}

string AbstractPlayer::getGridRow(int row) {
    string s;
    for (int i = 0; i < colNum; i++) {
        s += grid[row][i].getType();
    }
    return s;
}

void AbstractPlayer::recalculateGrid() {
   bool shouldClear;
   int offset = 0;
   for (int row = rowNum - 1; row > reservedRowNum; row--) {
        shouldClear = false;
       for (int col = 0; col < colNum; col++) {
            if ((grid[row][col].getType() != " ") && (col == colNum - 1)) shouldClear = true;
            if (grid[row][col].getType() == " ") break; 
        }

        if(shouldClear) {
            clearRow(row);
            offset++;
        } else {
            shiftRowDown(row, offset);
        }
   }
    recalculateInactiveBlocks();
}

void AbstractPlayer::clearRow(int row) {
   for(int col=0; col<colNum; col++){
        Point *p = &this->grid[row][col];
        p->setType(" ");
        auto ab = inactiveBlocks[p->getID()];
        for(auto cell : ab->getPoints()){
            if(cell == p){
                ab.get()->removeOnePoint(p);
            }
        }
        p->setID(-1);
   }
}

void AbstractPlayer::shiftRowDown(int row, int offset) {
    if (row < reservedRowNum || offset == 0) return; //checks if were within correct range
    for (int col =0; col < colNum; col++) { // iterates through the columns in the current row
      Point *p = &grid[row][col];// gets the point to be moved
      if (p->getType() != " ") {
        auto ab = inactiveBlocks[p->getID()];// finds the block the point is a part of
        Point *newP = &grid[row+offset][col]; // finds the place the point needs to be moved
        newP->setID(p->getID());// changes id
        p->setID(-1);
        for (auto cell : ab->getPoints()) {
             if (cell == p) {//once we find the point in the block...
                pair<int, int> coor = make_pair(newP->getX(), newP->getY());
                ab.get()->addPoint(coor, this); // creates the point that it should be moved to
                grid[row][col].setType(" ");
                ab.get()->removeOnePoint(p);// removes the current point from the block
            }

         }
        }
    }
}
void AbstractPlayer::recalculateInactiveBlocks(){
    for(auto entry : inactiveBlocks){
        if (entry.second->getPoints().size() == 0){
            currenntScore+=entry.second->getScore();
            inactiveBlocks.erase(entry.first);
        }
    }

}
/*void AbstractPlayer::recalculateFieldBlocks() {
    vector<shared_ptr<AbstractBlock>> newFieldBlocks;
    for (int i = 0; i < (int)this->fieldBlocks.size(); i++) {
        if (this->fieldBlocks[i].get()->getPoints().size()!= 0) {
            newFieldBlocks.emplace_back(this->fieldBlocks[i]);
        } else {
            this->currenntScore += this->fieldBlocks[i].get()->getScore();
        }
    }
    this->fieldBlocks = newFieldBlocks;
}

*/

// observer pattern
void AbstractPlayer::notifyGameover() {
    this->game->setGameOver();
}

void AbstractPlayer::notifyTurnover() {
   this->game->turnOver();
}

void AbstractPlayer::notifySpecialAction() {
    this->game->specialAction();
}

// getter
int AbstractPlayer::getCurrentScore() {
    return this->currenntScore;
}

int AbstractPlayer::getHighestScore() {
    return this->highestScore;
}

int AbstractPlayer::getLevel() {
    return this->level->getLevel();
}

string AbstractPlayer::getNextBlock() {
    return this->nextBlock->getType();
}

Point* AbstractPlayer::getPoint(pair<int, int> &c) {
  return &grid[c.second][c.first];
}
