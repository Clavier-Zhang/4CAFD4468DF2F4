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
using namespace std;

// constructor
AbstractPlayer::AbstractPlayer(Game *game, Xwindow *xw) {
    this->level = new LevelOne();
    this->currentBlock = this->level->generateBlock();
    this->nextBlock = this->level->generateBlock();
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
    this->game = game;
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

string AbstractPlayer::getGridRow(int row) {
    string s;
    for (int i = 0; i < colNum; i++) {
        s += this->grid[row][i].getType();
    }
    return s;
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

