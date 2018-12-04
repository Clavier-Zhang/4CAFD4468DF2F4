#include "blindDecorator.h"
#include "abstractDecorator.h"
#include "game.h"
using namespace std;

// Useful constants
const int MIN_ROW_BOUND = 3;
const int MAX_ROW_BOUND = 12;
const int MIN_COL_BOUND = 2;
const int MAX_COL_BOUND = 8;

BlindDecorator::BlindDecorator(shared_ptr<AbstractPlayer> absPlayer, Game *g, Xwindow * w) : 
AbstractDecorator{absPlayer, g, w} {
}

BlindDecorator::~BlindDecorator() {
}

// add the points of blocks to grid, update the block in drop(), 
void BlindDecorator::drop(bool shouldClearBlind) {
 player->drop(true);
}

shared_ptr<AbstractPlayer> BlindDecorator::getUnderlyingPlayer() {
 return player;
}

void BlindDecorator::nullifyUnderlyingPlayer() {
 player = nullptr;
}

void BlindDecorator::setLevel(int level) {
 player->setLevel(level);
}

int BlindDecorator::getHighScore(){
    return player->getHighScore();
}
int BlindDecorator::getCurrentScore() {
    return player->getCurrentScore();
}


void BlindDecorator::setHighScore(int hi){
    player->setHighScore(hi);
}

int BlindDecorator::getLevel() {return player->getLevel();}
int BlindDecorator::getNumDrop(){
    return player->getNumDrop();
}
void BlindDecorator::setRandom(bool rand, string file) {
    player->setRandom(rand, file);
}

void BlindDecorator::setNumDrop(int n){
    player->setNumDrop(n);
}
void BlindDecorator::setUnderlyingPlayer(shared_ptr<AbstractPlayer> play) {
 player = play;
 // UNLESS YOU MADE A COPY SOMETHERE THIS WILL DESTROY IT BEWARE
}

shared_ptr<AbstractPlayer> BlindDecorator::getBasePlayer() {
 shared_ptr<AbstractPlayer> tmp = getUnderlyingPlayer();
 while (tmp->getUnderlyingPlayer() != nullptr) {
  tmp = tmp->getUnderlyingPlayer();
  }
  return tmp;
}

int BlindDecorator::rotate(bool counter, int step, bool isBlind){
return player->rotate(counter, step, true);
}

void BlindDecorator::drawGridPoint(int x, int y, int col) {
 player->drawGridPoint(x, y, col);
 }

string BlindDecorator::getGridPoint(int row, int col) {
 if (((MIN_ROW_BOUND + reservedRowNum  <= row) && (row <= MAX_ROW_BOUND + reservedRowNum)) && ((MIN_COL_BOUND <= col) && (col <= MAX_COL_BOUND))) {
 drawGridPoint(col, row + 3, 8); // orange
 return "?";
 }
 return player->getGridPoint(row, col);
}

string BlindDecorator::getGridRow(int row){
 if (!(( MIN_ROW_BOUND + reservedRowNum <= row) && (row <= MAX_ROW_BOUND + reservedRowNum))) return player->getGridRow(row);
 string s;
 for (int i = 0; i < colNum; i++) {
    s += getGridPoint(row, i);
 }
 return s;
}

void BlindDecorator::setCurrentBlock(char c) {
 player->setCurrentBlock(c);
 }

int BlindDecorator::move(string type, int step, bool isBlind){
 return player->move(type, step, true);
}

