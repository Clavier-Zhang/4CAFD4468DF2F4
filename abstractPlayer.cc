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
    this->level = shared_ptr<AbstractLevel>(new LevelZero());
    this->currentBlock = this->level->generateBlock();
    this->nextBlock = this->level->generateBlock();
    this->currentBlock->initialize(this);
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
        s += this->grid[row][i].getType();
    }
    return s;
}

void AbstractPlayer::recalculateGrid() {
    int count = 0;
    for (int i = this->rowNum - 1; i >= 0; i--) {
        if (isFull(i)) {
            cout << "full !!!" << endl;
            count++;
            clearRow(i);
            moveAllHigherRowDown(i);
        }
    }
    if (count >= 2) this->notifySpecialAction();
    if (count > 0) {
        this->currenntScore += 
            (this->level->getLevel() + count) * 
            (this->level->getLevel() + count);
        this->recalculateFieldBlocks();
    }
    if (this->currenntScore > this->highestScore) {
        this->highestScore = this->currenntScore;
    }
}

void AbstractPlayer::clearRow(int row) {
    // reset each point in the row
    for (int i = 0; i < this->colNum; i++) {
        Point *p = &this->grid[row][i];
        p->setType(" ");
        // check this point with each block in the block field
        for (int j = 0; j < (int)this->fieldBlocks.size(); j++) {
            for (Point *old : this->fieldBlocks[j].get()->getPoints()) {
                if (old == p) {
                    this->fieldBlocks[j].get()->removeOnePoint(p);
                }
            }
        }
    }
}

void AbstractPlayer::recalculateFieldBlocks() {
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

void AbstractPlayer::moveOneHigherRowDown(int row) {
    if (row <= 0) return;
    for (int i = 0; i < this->colNum; i++) {
        this->grid[row][i].setType(this->grid[row-1][i].getType());
        this->grid[row-1][i].setType(" ");
    }
}

void AbstractPlayer::moveAllHigherRowDown(int row) {
    if (row <= 0) return;
    for (int i = row; i > 0; i--) {
        this->moveOneHigherRowDown(i);
    }
}

bool AbstractPlayer::isFull(int row) {
    for (int i = 0; i < this->colNum; i++) {
        if (this->grid[row][i].getType() == " ") {
            return false;
        }
    }
    return true;
}

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
