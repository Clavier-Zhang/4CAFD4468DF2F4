#include "abstractPlayer.h"
#include "game.h"
#include "abstractLevel.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"
#include "point.h"
#include <string.h>
#include "window.h"
#include "coordinate.h"
#include <memory>
using namespace std;

// constructor
AbstractPlayer::AbstractPlayer(Game *game, Xwindow *xw) {
    this->level = shared_ptr<AbstractLevel>(new LevelOne());
    this->currentBlock = shared_ptr<AbstractBlock>(this->level->generateBlock());
    this->nextBlock = shared_ptr<AbstractBlock>(this->level->generateBlock());
    this->xw = xw;
    // set grid
    for (int i = 0; i < this->rowNum; i++) {
        vector<Point> row;
        for (int j = 0; j < colNum; j++) {
            string empty = " ";
            row.emplace_back(Point(j,i,empty, xw));
        }
        this->grid.emplace_back(row);
    }
    this->currentBlock->initialize(this);
    this->game = game;
}

// important
void AbstractPlayer::updateCurrentBlock() {
    cout << this->currentBlock->getType() << endl;
    // this->currentBlock->removeAllPoint();
    // this->currentBlock.reset(this->nextBlock.get());
    // this->nextBlock.reset(this->level->generateBlock());
    // add poitns
}


string AbstractPlayer::getGridRow(int row) {
    string s;
    for (int i = 0; i < colNum; i++) {
        s += this->grid[row][i].getType();
    }
    return s;
}

Point* AbstractPlayer::getPoint(Coordinate &c) {
    return &this->grid[c.getY()][c.getX()];
}

// observer pattern
void AbstractPlayer::notifyGameover() {
    this->game->gameOver();
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