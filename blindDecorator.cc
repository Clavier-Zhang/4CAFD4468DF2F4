#include "blindDecorator.h"
#include "abstractDecorator.h"
using namespace std;

// Useful constants
const int MIN_ROW_BOUND = 2;
const int MAX_ROW_BOUND = 11;
const int MIN_COL_BOUND = 2;
const int MAX_COL_BOUND = 8;

BlindDecorator::BlindDecorator(shared_ptr<AbstractPlayer> absPlayer, Game *g, Xwindow * w) : 
AbstractDecorator{absPlayer, g, w} {}

BlindDecorator::~BlindDecorator() {}

// add the points of blocks to grid, update the block in drop(), 
void BlindDecorator::drop() {
 player->drop();
}

shared_ptr<AbstractPlayer> BlindDecorator::getUnderlyingPlayer() {
 return player;
}

void BlindDecorator::nullifyUnderlyingPlayer() {
 player = nullptr;
}

int BlindDecorator::rotate(bool counter, int step){
 return player->rotate(counter, step);
}

string BlindDecorator::getGridPoint(int row, int col) {
 if (((MIN_ROW_BOUND + reservedRowNum  <= row) && (row <= MAX_ROW_BOUND + reservedRowNum)) && ((MIN_COL_BOUND <= col) && (col <= MAX_COL_BOUND))) return "?";
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
int BlindDecorator::move(string type, int step){
 return player->move(type, step);
}
